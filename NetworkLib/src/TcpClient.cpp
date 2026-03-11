#include "TcpClient.h"

#include "TcpSocket.h"

#include <asio/connect.hpp>
#include <asio/write.hpp>
#include <spdlog/spdlog.h>

TcpClient::TcpClient(PrivateConstructor, asio::io_context& context)
	: context_(context)
    , resolver_(std::make_shared<asio::ip::tcp::resolver>(context_))
{

}

TcpClient::~TcpClient()
{

}

TcpClientPtr TcpClient::create(asio::io_context& context)
{
	return std::make_shared<TcpClient>(PrivateConstructor{}, context);
}

void TcpClient::connectTo(std::string host, std::uint16_t port)
{
	SPDLOG_INFO("{}:{}", host, port);

	// TODO: make sure you call it only once
    host_ = std::move(host);
    port_ = port;

    auto callback = [this, weak = weak_from_this(), resolver = resolver_](const asio::error_code& ec, asio::ip::tcp::resolver::results_type endpoints)
	{
		if (auto shared = weak.lock())
		{
			onConnectionResolved(ec, endpoints);
		}
		else
		{
            SPDLOG_WARN("TcpClient object already destroyed");
		}
	};

    resolver_->async_resolve(host_, std::to_string(port_), callback);
}

void TcpClient::onConnectionResolved(const asio::error_code& ec, asio::ip::tcp::resolver::results_type endpoints)
{
	SPDLOG_DEBUG("");

	if (!ec)
	{
        auto socket = std::make_shared<asio::ip::tcp::socket>(context_);

        auto callback = [this, weak = weak_from_this(), socket](const asio::error_code& ec, const asio::ip::tcp::endpoint& endpoint)
		{
			if (auto shared = weak.lock())
			{
                auto tcpSocket = TcpSocket::create(std::move(*socket));
                onConnectionEstablished(ec, endpoint, tcpSocket);
			}
			else
			{
				SPDLOG_WARN("TcpClient object already destroyed");
			}
		};

        asio::async_connect(*socket, endpoints, callback);
	}
	else
	{
		SPDLOG_ERROR("{}", ec.message());
	}
}

void TcpClient::onConnectionEstablished(const asio::error_code& ec, const asio::ip::tcp::endpoint& endpoint, TcpSocketPtr socket)
{
	if (!ec)
	{
		SPDLOG_INFO("Connected to {}:{}", host_, port_);

        socket_ = std::move(socket);
#if 0
        socket_->setErrorCallback([weak = weak_from_this()]{
            if (auto shared = weak.lock())
            {
                SPDLOG_ERROR("Socket error!");
            }
            else
            {
                SPDLOG_WARN("TcpClient object already destroyed");
            }
        });
#endif

        static std::string msg = "Hello from async client\n";

		auto callback = [this, shared = shared_from_this()](const asio::error_code& ec, std::size_t bytes_transferred)
		{
            SPDLOG_INFO("Bytes transferred: {}", bytes_transferred);
		};

        asio::async_write(socket_->native(), asio::buffer(msg), callback);
	}
	else
	{
		SPDLOG_ERROR("{}", ec.message());
	}
}
