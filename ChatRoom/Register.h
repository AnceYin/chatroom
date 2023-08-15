#pragma once

#include <QMainWindow>
#include "ui_Register.h"

class Register : public QMainWindow
{
	Q_OBJECT

public:
	Register(QWidget *parent = nullptr);
	~Register();

private slots:
	void RegisterPushButtonClicked();//点击注册按钮查询数据库用户名是否存在
	void SignInClicked();//点击Sign in调用的槽函数

private:
	Ui::RegisterClass ui;
};
