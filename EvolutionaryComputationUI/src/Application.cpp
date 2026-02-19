#include "Application.h"

#include "MainWindow.h"

#include <JsonFile.h>
#include <LoggerInitializer.h>
#include <TcpClient.h>

#include <asio/executor_work_guard.hpp>
#include <asio/io_context.hpp>
#include <QApplication>
#include <spdlog/spdlog.h>

int Application::exec(int argc, char* argv[])
{
	nlohmann::json settings = JsonFile::load("settings.json");

	LoggerInitializer logger(settings.value("logger", nlohmann::json::object()));

	SPDLOG_INFO("\n{}", settings.dump(4));

#if 0
	asio::io_context context;

	std::uint16_t port = 2026;
	if (port < 1024)
	{
		SPDLOG_ERROR("Tcp port number must be in range 1024 - 65535");
		return 0;
	}

	auto client = TcpClient::create(context);
	client->connectTo("localhost", port);
	//server->setConnectionCallback([](AbstractSocket&& socket) { SPDLOG_INFO("New connection"); });
	//if (!server->listen(port))
	//{
	//	SPDLOG_ERROR("TcpServer error!");
	//	return 1;
	//}

	context.run();
#endif

	QApplication app(argc, argv);

	MainWindow window;
	window.setWindowTitle("Evolutionary Computation UI");
	//window.setWindowIcon();
	window.show();

	return app.exec();
}
