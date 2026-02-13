#include "Application.h"

#include <TcpServer.h>

#include <asio/io_context.hpp>
#include <asio/executor_work_guard.hpp>
#include <spdlog/spdlog.h>

int Application::exec(int argc, char* argv[])
{
	SPDLOG_INFO("");

	asio::io_context context;

	std::uint16_t port = 2026;
	if (port < 1024)
	{
		SPDLOG_ERROR("Tcp port number must be in range 1024 - 65535");
		return 0;
	}

	auto server = TcpServer::create(context);
	if (!server->listen(port))
	{
		return 1;
	}

	std::uint16_t peerPort = 2026;
	if (peerPort < 1024)
	{
		SPDLOG_ERROR("Tcp port number must be in range 1024 - 65535");
		return 0;
	}

	auto peerServer = TcpServer::create(context);
	if (!peerServer->listen(peerPort))
	{
		return 1;
	}

	context.run();

	return 0;
}
