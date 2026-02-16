#pragma once

#include <AbstractSocket.h>

#include "TcpServerPtr.h"

#include <asio/io_context.hpp>
#include <asio/ip/tcp.hpp>
#include <cstdint>
#include <functional>
#include <memory>

class TcpServer
	: public std::enable_shared_from_this<TcpServer>
{
	struct PrivateConstructor {};

public:
	explicit TcpServer(PrivateConstructor, asio::io_context& context);

	static TcpServerPtr create(asio::io_context& context);

	void setConnectionCallback(std::function<void(AbstractSocket&&)> callback);

	[[nodiscard]]
	bool listen(std::uint16_t port);

protected:
	void accept();
	void onConnectionAccepted(std::error_code ec, asio::ip::tcp::socket socket);

private:
	asio::io_context& context_;
	std::unique_ptr<asio::ip::tcp::acceptor> acceptor_;
	std::function<void(AbstractSocket&&)> callback_ = nullptr;
};
