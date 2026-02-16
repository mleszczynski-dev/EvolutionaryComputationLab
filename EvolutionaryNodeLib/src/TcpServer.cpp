#include "TcpServer.h"

#include <TcpSocket.h>

#include <spdlog/spdlog.h>

namespace
{

int MAX_PENDING_CONNECTIONS = 32;

} // namespace

TcpServer::TcpServer(PrivateConstructor, asio::io_context& context)
	: context_(context)
{

}

TcpServerPtr TcpServer::create(asio::io_context& context)
{
    return std::make_shared<TcpServer>(PrivateConstructor{}, context);
}

void TcpServer::setConnectionCallback(std::function<void(AbstractSocket&&)> callback)
{
    callback_ = std::move(callback);
}

bool TcpServer::listen(std::uint16_t port)
{
    SPDLOG_INFO("Port: {}", port);

    bool error = false;

    asio::ip::tcp::endpoint endpoint(asio::ip::tcp::v4(), port);

    try
    {
        acceptor_ = std::make_unique<asio::ip::tcp::acceptor>(context_);
        acceptor_->open(endpoint.protocol());
        acceptor_->set_option(asio::socket_base::reuse_address(true));
        acceptor_->bind(endpoint);
        acceptor_->listen(MAX_PENDING_CONNECTIONS);
    }
    catch (const std::system_error& e)
    {
        SPDLOG_ERROR("{}", e.what());

        error = true;
    }

    if (!error)
    {
        accept();
    }

	return !error;
}

void TcpServer::accept()
{
    SPDLOG_DEBUG("");

    auto callback = [this, weak = weak_from_this()](std::error_code ec, asio::ip::tcp::socket socket)
    {
        if (auto shared = weak.lock())
        {
            onConnectionAccepted(ec, std::move(socket));
        }
        else
        {
            SPDLOG_WARN("TcpServer object already destroyed");
        }
    };

    acceptor_->async_accept(callback);
}

void TcpServer::onConnectionAccepted(std::error_code ec, asio::ip::tcp::socket socket)
{
    SPDLOG_DEBUG("");

    if (!ec)
    {
        TcpSocket tcpSocket(std::move(socket));
        //if (callback_) callback_(std::move(tcpSocket));
    }
    else
    {
        SPDLOG_ERROR("{}", ec.message());
    }

    accept();
}

