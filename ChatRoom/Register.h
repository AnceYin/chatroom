#pragma once

#include <QMainWindow>
#include "ui_Register.h"
#include "TcpConnection.h"
#include "serialize/DataStream.h"
#include "serialize/Serializable.h"
#include <iostream>

class Register : public QMainWindow
{
	Q_OBJECT

public:
	Register(QWidget *parent = nullptr);
	~Register();

private slots:
	void RegisterPushButtonClicked();//点击注册按钮查询数据库用户名是否存在
	void returnPushButtonClicked();
	void onDataReceived(const QByteArray& data);

private:
	Ui::RegisterClass ui;
	TcpSingleton* m_tcpConn;
};
