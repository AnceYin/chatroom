#include "Login.h"
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

	//// 进行用户名和密码验证的逻辑
	//if (username == "admin" && password == "123456") {
	//	QMessageBox::information(this, "登录成功", "欢迎，" + username);
	//}
	//else {
	//	QMessageBox::critical(this, "登录失败", "用户名或密码错误");
	//}

	int64_t msg1 = 1000, msg2;
	msg2 = 29999;
	DataStream ds;
	std::string a = "无语", b = "123";
	ds << msg1 << msg2 << a << b;
	//QByteArray data = ds.data();<< msg2 << a << b

	ds >> msg1 >> msg2 >> a >> b;
	ui.usernameLineEdit->setText(QString::number(msg1));
	ui.usernameLineEdit->setText(stdStrToQstr(a));
	//QFile file("out.dat");
	//if (!file.open(QIODevice::WriteOnly)) {
	//	//错误处理
	//}
	//file.write(data);
	//file.close();

	//m_tcpConn->sendData(ds.data(), ds.size());
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
	// Process received data
	int32_t msgType, msgSize;
	std::string stdString(data.constData(), data.size());

	std::string a, b;

	DataStream ds(stdString);
	ds >> a >> b;

	ui.usernameLineEdit->setText(stdStrToQstr(a));
	ui.usernameLineEdit->setText(stdStrToQstr(b));
}

