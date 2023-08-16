#include "Login.h"
#include <QMessageBox>
#include <QTcpSocket>

Login::Login(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

Login::~Login()
{}

void Login::LoginPushButtonClicked()
{
	// 获取用户输入
	QString username = ui.usernameLineEdit->text();
	QString password = ui.passwordLineEdit->text();


	// 进行用户名和密码验证的逻辑
	if (username == "admin" && password == "123456") {
		QMessageBox::information(this, "登录成功", "欢迎，" + username);
	}
	else {
		QMessageBox::critical(this, "登录失败", "用户名或密码错误");
	}
}

void Login::SignUpClicked()
{

}

void Login::ForgetPasswordClicked()
{

}
