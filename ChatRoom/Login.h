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
	void LoginPushButtonClicked();//�����¼��ť��ѯ���ݿ�Ƚ��û����������Ƿ���ȷ
	void SignUpClicked();//���Sign up���õĲۺ���
	void ForgetPasswordClicked();//���Forget password���õĲۺ���

private:
	Ui::LoginClass ui;
};
