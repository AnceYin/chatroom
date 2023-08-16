#pragma once

#include <QMainWindow>
#include "ui_Login.h"

class Login : public QMainWindow
{
	Q_OBJECT

public:
	Login(QWidget *parent = nullptr);
	~Login();

private slots:
	void LoginPushButtonClicked();// 点击登录按钮查询数据库比较用户名和密码是否正确
	void SignUpClicked();// 点击Sign up调用的槽函数
	void ForgetPasswordClicked();// 点击Forget password调用的槽函数

private:
	Ui::LoginClass ui;
};
