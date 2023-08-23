#pragma once

#include <QMainWindow>
#include "ui_Add.h"
#include "TcpConnection.h"
#include "serialize/DataStream.h"
#include "serialize/Serializable.h"
#include <iostream>
class Add : public QMainWindow
{
	Q_OBJECT

public:
	Add(QWidget *parent = nullptr);
	~Add();

private slots:
	void CreatPushButtonClicked();//创建群聊按钮
	void onDataReceived(const QByteArray& data);//接收消息

private:
	Ui::AddClass ui;
	TcpSingleton* m_tcpConn;
};
