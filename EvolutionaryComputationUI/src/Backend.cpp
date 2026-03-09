#include "Backend.h"

#include <spdlog/spdlog.h>

Backend::Backend(QObject *parent)
    : QObject(parent), m_message("Hello from C++")
{
    QObject::connect(this, &Backend::welcomeClicked, this, &Backend::onWelcomeClicked);
}

void Backend::onWelcomeClicked()
{
    SPDLOG_INFO("");
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

void Backend::generateMessage()
{
    setMessage("Nowa wiadomość z backendu!");
}
