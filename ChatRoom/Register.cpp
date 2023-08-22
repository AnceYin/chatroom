#include "Register.h"
#include "Login.h"
#include <QMessageBox>
#include <QTcpSocket>
#include "net.cpp"
#include <QString>
#include <QTextCodec>
#pragma execution_character_set("UTF-8")

Register::Register(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	m_tcpConn = TcpSingleton::instance();
	connect(m_tcpConn, &TcpSingleton::dataReceived, this, &Register::onDataReceived);
	connect(ui.pushButton, &QPushButton::clicked, this, &Register::returnPushButtonClicked);
	connect(ui.pushButton_2, &QPushButton::clicked, this, &Register::RegisterPushButtonClicked);
}

Register::~Register()
{}

void Register::RegisterPushButtonClicked()
{
	//获取用户输入
	if ((ui.lineEdit_2->text() == ui.lineEdit_3->text())&&ui.lineEdit->text()!=NULL)
	{
		QString username = ui.lineEdit->text();
		QString password = ui.lineEdit_3->text();
		QString data = "01|" + username + "|" + password;
		QByteArray sdata = data.toLatin1();
		
		m_tcpConn->sendData(sdata, sdata.size());
	}
	else if (ui.lineEdit->text() == NULL)
	{
		QMessageBox::warning(this,
			tr("注册"),
			tr("用户名请不要为空！"),
			QMessageBox::Ok | QMessageBox::Cancel,
			QMessageBox::Ok);
	}
	else {
		QMessageBox::warning(this,
			tr("注册"),
			tr("两次输入密码不一样，请重新输入！"),
			QMessageBox::Ok | QMessageBox::Cancel,
			QMessageBox::Ok);
	}
}

void Register::returnPushButtonClicked()
{
	Login* l = new Login;
	l->show();
	this->close();
}

// 处理收到消息函数
void Register::onDataReceived(const QByteArray& data)
{
	QString receData = QString(data);
	if (receData[0] != '0' || receData[1] != '1') return;
	QString user_id;
	for (int i = 3; i < receData.length(); i++) {
		user_id.append(receData[i]);
	}
	QByteArray userid = user_id.toLatin1();

	QMessageBox::information(this,
		tr("注册"),
		tr("注册成功！你的账号是"+userid+",快去登录吧！"),
		QMessageBox::Ok | QMessageBox::Cancel,
		QMessageBox::Ok);
}