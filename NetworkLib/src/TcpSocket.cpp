#include "TcpSocket.h"

TcpSocket::TcpSocket(asio::ip::tcp::socket&& socket)
	: socket_(std::move(socket))
{

}

TcpSocket::~TcpSocket()
{

}

