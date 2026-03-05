#pragma once

#include <QObject>

class Backend : public QObject
{
    Q_OBJECT

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
