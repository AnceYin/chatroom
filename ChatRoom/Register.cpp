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
	//��ȡ�û�����
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
			tr("ע��"),
			tr("�û����벻ҪΪ�գ�"),
			QMessageBox::Ok | QMessageBox::Cancel,
			QMessageBox::Ok);
	}
	else {
		QMessageBox::warning(this,
			tr("ע��"),
			tr("�����������벻һ�������������룡"),
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

// �����յ���Ϣ����
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
		tr("ע��"),
		tr("ע��ɹ�������˺���"+userid+",��ȥ��¼�ɣ�"),
		QMessageBox::Ok | QMessageBox::Cancel,
		QMessageBox::Ok);
}