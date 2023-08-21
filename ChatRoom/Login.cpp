#include "Login.h"
#include "ChatRoom.h"
#include <QMessageBox>
#include <QTcpSocket>
#include "net.cpp"
#include <QString>
#include <QTextCodec>

std::string qstrToStdStr(const QString& qstr)
{
	QTextCodec* codec = QTextCodec::codecForName("UTF-8");
	QByteArray encodedData = codec->fromUnicode(qstr);
	return encodedData.constData();
}

QString stdStrToQstr(const std::string& stdStr)
{
	QTextCodec* codec = QTextCodec::codecForName("UTF-8");
	QString qstr = codec->toUnicode(stdStr.c_str());
	return qstr;
}

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
	QString username = ui.usernameLineEdit->text();
	QString password = ui.passwordLineEdit->text();
	QString data = "00|"+username + "|" + password;
	QByteArray sData = data.toLatin1();

	m_tcpConn->sendData(sData, 40);
	
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
	for (int i = 0; i < receData.length(); i++) {
		if (receData[i] == "|") {
			if (receData[i + 1] == "1") {
				QMessageBox::question(this,
					tr("登录"),
					tr("登录成功，开始和他人聊天吧！"),
					QMessageBox::Ok | QMessageBox::Cancel,
					QMessageBox::Ok);
				ChatRoom ch;
				ch.show();
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

