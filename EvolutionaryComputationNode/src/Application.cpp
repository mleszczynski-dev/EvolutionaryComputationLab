#include "Application.h"

#include <JsonFile.h>
#include <LoggerInitializer.h>
#include <TcpClient.h>
#include <TcpServer.h>

#include <asio/io_context.hpp>
#include <asio/executor_work_guard.hpp>
#include <spdlog/spdlog.h>

int Application::exec(int argc, char* argv[])
{
	nlohmann::json settings = JsonFile::load("settings.json");

	LoggerInitializer logger(settings.value("logger", nlohmann::json::object()));

	SPDLOG_INFO("\n{}", settings.dump(4));

	asio::io_context context;

	std::uint16_t port = 2026;
	if (port < 1024)
	{
		SPDLOG_ERROR("Tcp port number must be in range 1024 - 65535");
		return 0;
	}

	auto server = TcpServer::create(context);
	server->setConnectionCallback([](AbstractSocket&& socket) { SPDLOG_INFO("New connection"); });
	if (!server->listen(port))
	{
		SPDLOG_ERROR("TcpServer error!");
		return 1;
	}

	std::uint16_t peerPort = 2027;
	if (peerPort < 1024)
	{
		SPDLOG_ERROR("Tcp port number must be in range 1024 - 65535");
		return 0;
	}

	auto peerServer = TcpServer::create(context);
	peerServer->setConnectionCallback([](AbstractSocket&& socket) { SPDLOG_INFO("New peer connection"); });
	if (!peerServer->listen(peerPort))
	{
		SPDLOG_ERROR("TcpServer peer error!");
		return 1;
	}

	context.run();

	return 0;
}
