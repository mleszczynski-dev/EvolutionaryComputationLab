#pragma once

#include "AbstractSocket.h"

#include <memory>

#include <asio/ip/tcp.hpp>

class TcpSocket
	: public AbstractSocket
	, public std::enable_shared_from_this<TcpSocket>
{
public:
	explicit TcpSocket(asio::ip::tcp::socket&& socket);
	~TcpSocket() override;

private:
	asio::ip::tcp::socket socket_;
};

