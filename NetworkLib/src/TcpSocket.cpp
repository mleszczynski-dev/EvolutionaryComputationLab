#include "TcpSocket.h"

#include <spdlog/spdlog.h>

TcpSocket::TcpSocket(/*PrivateConstructor, */asio::ip::tcp::socket&& socket)
	: socket_(std::move(socket))
{
	SPDLOG_TRACE("");
}

TcpSocket::~TcpSocket()
{
	SPDLOG_TRACE("");
}

TcpSocketPtr TcpSocket::create(asio::ip::tcp::socket&& socket)
{
    return std::make_shared<TcpSocket>(/*PrivateConstructor{}, */std::move(socket));
}

asio::ip::tcp::socket& TcpSocket::native()
{
    return socket_;
}

void TcpSocket::close()
{
    std::error_code ec;
    socket_.close(ec);

    if(ec)
    {
        SPDLOG_ERROR("{}", ec.message());
    }
}
