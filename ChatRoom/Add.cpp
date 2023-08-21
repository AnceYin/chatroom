#include "Add.h"
#include <QMessageBox>
#include <QTcpSocket>
#include "net.cpp"
#include <QString>
#include <QTextCodec>


Add::Add(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	m_tcpConn = TcpSingleton::instance();
	ui.lineEdit->setPlaceholderText(QString::fromLocal8Bit("Group Name?"));
	//建立连接
	connect(m_tcpConn, &TcpSingleton::dataReceived, this, &Add::onDataReceived);
	connect(ui.create, &QPushButton::clicked, this, &Add::CreatPushButtonClicked);

}

Add::~Add()
{}

void Add::CreatPushButtonClicked()
{
	//创建群聊
	if (ui.lineEdit->text() != NULL)
	{
		QString team_name = ui.lineEdit->text();
		QString user_id = "001";
		QString data = "04|";
		data.append(user_id);
		data.append("|");
		data.append(team_name);
		QByteArray newdata = data.toLatin1();
		m_tcpConn->sendData(newdata, 30);
	}
}

void Add::onDataReceived(const QByteArray& data) {
	QString receData = QString(data);
	QString team_id;
	for (int i = 3; i < receData.length() - 3; i++)
	{
		team_id.append(receData[i]);
	}
	QString msg = "群聊";
	msg.append(team_id);
	msg.append("创建成功！");
	QByteArray ba;
	char* ptr;
	ba = msg.toLatin1();
	ptr = ba.data();

	QMessageBox::question(this,
		tr("创建群聊"),
		tr(ptr),
		QMessageBox::Ok | QMessageBox::Cancel,
		QMessageBox::Ok);
}