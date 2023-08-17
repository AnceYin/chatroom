#include "CreatGroup.h"

CreatGroup::CreatGroup(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.lineEdit->setPlaceholderText(QString::fromLocal8Bit("Search your friend"));

	//切换界面
	connect(ui.list_contact, &QListWidget::itemClicked, this, &CreatGroup::onItemClicked);
}

CreatGroup::~CreatGroup()
{}

void CreatGroup::onItemClicked(QListWidgetItem* item)
{
	if (item->text() == "New Contact") //添加新的联系人
	{
		ui.label->setText(item->text());
		ui.lineEdit->setPlaceholderText(QString::fromLocal8Bit("Search your friend"));
	}
	else if (item->text() == "Join a Group") //加入群聊
	{
		ui.label->setText(item->text());
		ui.lineEdit->setPlaceholderText(QString::fromLocal8Bit("Search the Group"));
	}
	else if (item->text() == "<<")//返回聊天界面
	{
		
	}
	else
	{

	}
	
}

