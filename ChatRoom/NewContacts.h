#pragma once

#include <QMainWindow>
#include "ui_NewContacts.h"

class NewContacts : public QMainWindow
{
	Q_OBJECT

public:
	NewContacts(QWidget *parent = nullptr);
	~NewContacts();
	void ShowMessage();//查询数据库获取消息(私聊信息和群聊信息)并显示消息
	void ShowNewContacts();//接受服务器发来的好友申请并显示

private slots:
	void ReturnPushButtonClicked();//返回上级页面
	void AcceptPushButtonClicked();//点击Accept按钮执行的操作
	void RefusePushButtonClicked();//点击Accept按钮执行的操作
	void MessageClicked();//点击消息显示聊天记录

private:
	Ui::NewContactsClass ui;
};
