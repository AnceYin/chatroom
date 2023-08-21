#include "CreatGroup.h"
#include "Add.h"
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

CreatGroup::CreatGroup(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	m_tcpConn = TcpSingleton::instance();
	ui.lineEdit->setPlaceholderText(QString::fromLocal8Bit("Search your friend"));

	//��������
	connect(ui.list_contact, &QListWidget::itemClicked, this, &CreatGroup::onItemClicked);
	connect(ui.search, &QPushButton::clicked, this, &CreatGroup::SearchClicked);
	connect(m_tcpConn, &TcpSingleton::dataReceived, this, &CreatGroup::onDataReceived);
}

CreatGroup::~CreatGroup()
{}

void CreatGroup::onItemClicked(QListWidgetItem* item)
{
	if (item->text() == "New Contact") //����µ���ϵ��
	{
		ui.label->setText(item->text());
		ui.lineEdit->setPlaceholderText(QString::fromLocal8Bit("Search your friend"));
	}
	else if (item->text() == "Join a Group") //����Ⱥ��
	{
		ui.label->setText(item->text());
		ui.lineEdit->setPlaceholderText(QString::fromLocal8Bit("Search the Group"));
	}
	else if (item->text() == "<<")//�����������
	{
		
	}
	else
	{
		Add *a = new Add;
		a->show();
	}
	
}
void CreatGroup::SearchClicked() {
	if (ui.label->text() == "New Contact")
	{
		//�����ϵ��
	}
	if (ui.label->text() == "Join a Group") {
		//����Ⱥ��
		QString team_id = ui.lineEdit->text();
		QString user_id = "001";
		QString data = "05|";
		data.append(user_id);
		data.append("|");
		data.append(team_id);
		QByteArray newdata = data.toLatin1();
		m_tcpConn->sendData(newdata,30);
	}
}

void CreatGroup::onDataReceived(const QByteArray& data) {
	QString receData = QString(data);
	for (int i = 0; i < receData.length(); i++) {
		if (receData[i] == "|") {
			if (receData[i + 1] == "1") {
				QMessageBox::question(this,
					tr("����Ⱥ��"),
					tr("��ϲ�㣬����ɹ���"),
					QMessageBox::Ok | QMessageBox::Cancel,
					QMessageBox::Ok);
				break;
			}
			if (receData[i + 1] == "0") {
				QMessageBox::question(this,
					tr("��������"),
					tr("����ʧ�ܣ���������ԭ��..."),
					QMessageBox::Ok | QMessageBox::Cancel,
					QMessageBox::Ok);
				break;
			}
		}
	}
}
