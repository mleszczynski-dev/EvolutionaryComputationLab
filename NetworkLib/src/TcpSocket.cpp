#include "TcpSocket.h"

#include <spdlog/spdlog.h>

TcpSocket::TcpSocket(asio::ip::tcp::socket&& socket)
	: socket_(std::move(socket))
{
	SPDLOG_TRACE("");
}

TcpSocket::~TcpSocket()
{
	SPDLOG_TRACE("");
}
