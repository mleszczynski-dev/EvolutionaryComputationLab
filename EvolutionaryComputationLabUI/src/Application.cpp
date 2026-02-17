#include "Application.h"

#include <Client.h>

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

	auto client = Client::create(context);
	client->connectTo("localhost", port);
	//server->setConnectionCallback([](AbstractSocket&& socket) { SPDLOG_INFO("New connection"); });
	//if (!server->listen(port))
	//{
	//	SPDLOG_ERROR("TcpServer error!");
	//	return 1;
	//}

	context.run();

	return 0;
}
