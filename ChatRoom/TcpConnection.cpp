// TcpSingleton.cpp

#include "TcpConnection.h"
#include <QHostAddress>

TcpSingleton* TcpSingleton::m_instance = nullptr;

TcpSingleton::TcpSingleton(QObject* parent) : QObject(parent)
{
    m_tcpSocket = new QTcpSocket(this);

    QString ip = "139.224.62.197";
    unsigned short port = 55369;
    m_tcpSocket->connectToHost(QHostAddress(ip), port);

    connect(m_tcpSocket, &QTcpSocket::readyRead, this, &TcpSingleton::onReadyRead);
}

TcpSingleton::~TcpSingleton()
{
    delete m_tcpSocket;
}

TcpSingleton* TcpSingleton::instance()
{
    if (!m_instance)
        m_instance = new TcpSingleton();
    return m_instance;
}

void TcpSingleton::connectToServer(const QString& serverAddress, quint16 port)
{
    m_tcpSocket->connectToHost(serverAddress, port);
}

void TcpSingleton::sendData(const QByteArray& data, qint64 len)
{
    m_tcpSocket->write(data, len);
    m_tcpSocket->flush();
}

void TcpSingleton::onReadyRead()
{
    QByteArray data = m_tcpSocket->readAll();
    emit dataReceived(data);
}