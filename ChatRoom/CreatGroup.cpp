#include "CreatGroup.h"

CreatGroup::CreatGroup(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.lineEdit->setPlaceholderText(QString::fromLocal8Bit("Search your friend"));

	//�л�����
	connect(ui.list_contact, &QListWidget::itemClicked, this, &CreatGroup::onItemClicked);
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

	}
	
}

