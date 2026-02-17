#include "TcpClient.h"

#include <asio/connect.hpp>
#include <asio/write.hpp>
#include <spdlog/spdlog.h>

TcpClient::TcpClient(PrivateConstructor, asio::io_context& context)
	: context_(context)
	, resolver_(context_)
	, socket_(context_)
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
	port_ = std::move(port);

	auto callback = [this, weak = weak_from_this()](const asio::error_code& ec, asio::ip::tcp::resolver::results_type endpoints)
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

	resolver_.async_resolve(host_, std::to_string(port_), callback);
}

void TcpClient::onConnectionResolved(const asio::error_code& ec, asio::ip::tcp::resolver::results_type endpoints)
{
	SPDLOG_DEBUG("");

	if (!ec)
	{
		auto callback = [this, weak = weak_from_this()](const asio::error_code& ec, const asio::ip::tcp::endpoint& endpoint)
		{
			if (auto shared = weak.lock())
			{
				onConnectionEstablished(ec, endpoint);
			}
			else
			{
				SPDLOG_WARN("TcpClient object already destroyed");
			}
		};

		asio::async_connect(socket_, endpoints, callback);
	}
	else
	{
		SPDLOG_ERROR("{}", ec.message());
	}
}

void TcpClient::onConnectionEstablished(const asio::error_code& ec, const asio::ip::tcp::endpoint& endpoint)
{
	if (!ec)
	{
		SPDLOG_INFO("Connected to {}:{}", host_, port_);

		std::string msg = "Hello from async client\n";

		auto callback = [this, shared = shared_from_this()](const asio::error_code& ec, std::size_t bytes_transferred)
		{

		};

		asio::async_write(socket_, asio::buffer(msg), callback);
	}
	else
	{
		SPDLOG_ERROR("{}", ec.message());
	}
}
