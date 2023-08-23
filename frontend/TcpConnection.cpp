// TcpSingleton.cpp

#include "TcpConnection.h"
#include <QHostAddress>

TcpSingleton* TcpSingleton::m_instance = nullptr;

TcpSingleton::TcpSingleton(QObject* parent) : QObject(parent)
{
    m_tcpSocket = new QTcpSocket(this);

    QString ip = "127.0.0.1";
    unsigned short port = 55360;
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
    if (m_tcpSocket->state() == QAbstractSocket::ConnectedState) {
        // Write data to the socket
        m_tcpSocket->write(data, len);
    }
    else {
        // Handle the error or try reconnecting
        qDebug() << "Socket is not open or connected.";
    }
}

void TcpSingleton::onReadyRead()
{
    QByteArray data = m_tcpSocket->readAll();
    emit dataReceived(data);
}