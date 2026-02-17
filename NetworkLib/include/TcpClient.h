#pragma once

#include "AbstractClient.h"
#include "TcpClientPtr.h"

#include <asio/io_context.hpp>
#include <asio/ip/tcp.hpp>
#include <cstdint>
#include <memory>
#include <string>

class TcpClient
	: public std::enable_shared_from_this<TcpClient>
	, public AbstractClient
{
	struct PrivateConstructor {};

public:
	explicit TcpClient(PrivateConstructor, asio::io_context& context);
	~TcpClient() override;

	static TcpClientPtr create(asio::io_context& context);

	void connectTo(std::string host, std::uint16_t port);
	//void reconnect();

	//void setConnectionListener();

protected:
	void onConnectionResolved(const asio::error_code& ec, asio::ip::tcp::resolver::results_type endpoints);
	void onConnectionEstablished(const asio::error_code& ec, const asio::ip::tcp::endpoint& endpoint);

private:
	asio::io_context& context_;
	asio::ip::tcp::resolver resolver_;
	asio::ip::tcp::socket socket_;
	std::string host_;
	std::uint16_t port_ = 0;

	enum { max_length = 1024 };
	char data_[max_length] { '\0' };
};
