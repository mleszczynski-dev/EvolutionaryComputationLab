#pragma once

#include "AbstractSocket.h"

#include <memory>

#include <asio/ip/tcp.hpp>

class TcpSocket
	: public AbstractSocket
	, public std::enable_shared_from_this<TcpSocket>
{
public:
	~TcpSocket() override;

	asio::ip::tcp::socket socket_;
};
