#include "Login.h"
#include "ChatRoom.h"
#include <QMessageBox>
#include <QTcpSocket>
#include "net.cpp"
#include <QString>
#include <QTextCodec>
#pragma execution_character_set("UTF-8")
QString user_id;

Login::Login(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	m_tcpConn = TcpSingleton::instance();
	connect(m_tcpConn, &TcpSingleton::dataReceived, this, &Login::onDataReceived);

	connect(ui.loginButton, &QPushButton::clicked, this, &Login::LoginPushButtonClicked);
}

Login::~Login()
{} 

void Login::LoginPushButtonClicked()
{
	// 获取用户输入
	user_id = ui.usernameLineEdit->text();
	QString password = ui.passwordLineEdit->text();
	QString data = "00|"+user_id + "|" + password;
	QByteArray sData = data.toLatin1();

	m_tcpConn->sendData(sData, sData.size());
	
}

void Login::SignUpClicked()
{

}

void Login::ForgetPasswordClicked()
{

}

// 处理收到消息函数
void Login::onDataReceived(const QByteArray& data)
{
	QString receData = QString(data);
	if (receData[0] != "0" || receData[1] != "0") return;
	for (int i = 0; i < receData.length(); i++) {
		if (receData[i] == "|") {
			if (receData[i + 1] == "1") {
				user_id = ui.usernameLineEdit->text();
				QMessageBox::question(this,
					tr("登录"),
					tr("登录成功，开始和他人聊天吧！"),
					QMessageBox::Ok | QMessageBox::Cancel,
					QMessageBox::Ok);
				ChatRoom* ch = new ChatRoom;
				ch->show();
				this->close();
				break;
			}
			if (receData[i + 1] == "0") {
				QMessageBox::question(this,
					tr("登录"),
					tr("登录失败，密码或用户名错误！"),
					QMessageBox::Ok | QMessageBox::Cancel,
					QMessageBox::Ok);
				break;
			}
		}
	}
}

