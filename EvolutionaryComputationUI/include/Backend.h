#pragma once

#include <QObject>
#include <qqml.h>

class Backend : public QObject
{
    Q_OBJECT
    QML_ELEMENT   // <- automatyczna rejestracja do QML (Qt 6)

    Q_PROPERTY(QString message READ message WRITE setMessage NOTIFY messageChanged)

public:
    explicit Backend(QObject *parent = nullptr);

    QString message() const;
    void setMessage(const QString &msg);

    Q_INVOKABLE void generateMessage();

signals:
    void messageChanged();

private:
    QString m_message;
};
