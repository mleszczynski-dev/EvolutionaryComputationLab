#pragma once

#include "AbstractSocket.h"
#include "TcpSocketPtr.h"

#include <memory>

#include <asio/ip/tcp.hpp>

class TcpSocket
	: public AbstractSocket
	, public std::enable_shared_from_this<TcpSocket>
{
    struct PrivateConstructor {};

public:
    explicit TcpSocket(/*PrivateConstructor, */asio::ip::tcp::socket&& socket);
	~TcpSocket() override;

    static TcpSocketPtr create(asio::ip::tcp::socket&& socket);

    asio::ip::tcp::socket& native();

private:
	asio::ip::tcp::socket socket_;
};
