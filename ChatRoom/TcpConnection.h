// TcpSingleton.h

#ifndef TCPSINGLETON_H
#define TCPSINGLETON_H

#include <QObject>
#include <QTcpSocket>

class TcpSingleton : public QObject
{
    Q_OBJECT
public:
    static TcpSingleton* instance();

    void connectToServer(const QString& serverAddress, quint16 port);
    void sendData(const QByteArray& data, qint64 len);

signals:
    void dataReceived(const QByteArray& data);

private slots:
    void onReadyRead();

private:
    TcpSingleton(QObject* parent = nullptr);
    ~TcpSingleton();

    static TcpSingleton* m_instance;
    QTcpSocket* m_tcpSocket;
};

#endif // TCPSINGLETON_H#pragma once
