#pragma once

#include <QMainWindow>
#include "ui_Login.h"
#include "TcpConnection.h"
#include "serialize/DataStream.h"
#include "serialize/Serializable.h"
#include <iostream>

using namespace yazi::serialize;

class Login : public QMainWindow
{
	Q_OBJECT

public:
	Login(QWidget* parent = nullptr);
	~Login();

private slots:
	void LoginPushButtonClicked();//点击登录按钮查询数据库比较用户名和密码是否正确
	void ForgetPasswordClicked();//点击Forget password调用的槽函数
	void RegisterClicked();//点击Register调用的槽函数
	void onDataReceived(const QByteArray& data);


private:
	Ui::LoginClass ui;
	TcpSingleton* m_tcpConn;
};
