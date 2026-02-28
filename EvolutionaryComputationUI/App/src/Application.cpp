#include "Application.h"

#include <JsonFile.h>
#include <LoggerInitializer.h>
#include <TcpClient.h>

#include <asio/executor_work_guard.hpp>
#include <asio/io_context.hpp>
#include <QApplication>
#include <spdlog/spdlog.h>

#include <QApplication>
#include <QQmlApplicationEngine>

#include "../autogen/environment.h"

#include <QObject>

class Backend : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString message READ message WRITE setMessage NOTIFY messageChanged)

public:
    explicit Backend(QObject *parent = nullptr);

    QString message() const;
    void setMessage(const QString &msg);

    Q_INVOKABLE void buttonClicked(); // metoda wywoływana z QML

signals:
    void messageChanged();

private:
    QString m_message;
};

Backend::Backend(QObject *parent)
    : QObject(parent), m_message("Witaj z C++")
{
}

QString Backend::message() const
{
    return m_message;
}

void Backend::setMessage(const QString &msg)
{
    if (m_message == msg)
        return;

    m_message = msg;
    emit messageChanged();
}

void Backend::buttonClicked()
{
    setMessage("Kliknięto przycisk!");
}

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

    SPDLOG_INFO(L"{}", std::filesystem::current_path().native());

	set_qt_environment();
	QApplication app(argc, argv);

	QQmlApplicationEngine engine;
	const QUrl url(mainQmlFile);
    for(const auto& path : engine.importPathList())
        SPDLOG_INFO("Import path: {}", path.toStdString());
    SPDLOG_INFO("Qml url: {}", mainQmlFile);
	QObject::connect(&engine, &QQmlApplicationEngine::objectCreated, &app,
		[url](QObject* obj, const QUrl& objUrl) {
			if (!obj && url == objUrl)
				QCoreApplication::exit(-1);
		}, Qt::QueuedConnection);

    Backend backend;
    //engine.rootContext()->setContextProperty("backend", &backend);

	engine.addImportPath(QCoreApplication::applicationDirPath() + "/qml");
	engine.addImportPath(":/");
	engine.load(url);

	if (engine.rootObjects().isEmpty())
		return -1;

	return app.exec();
}
