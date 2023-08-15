#pragma once

#include <QMainWindow>
#include "ui_Add.h"

class Add : public QMainWindow
{
	Q_OBJECT

public:
	Add(QWidget *parent = nullptr);
	~Add();

private slots:
	void ReturnPushButtonClicked();//返回上级目录
	void NewContactPushButtonClicked();//点击New Contact添加好友
	void CreatAGroupPushButtonClicked();//点击Creat a group跳转到Creating a group页面
	void SerachPushButtonClicked();//点击serach查找用户或群聊
	void JoinAGroupPushButtonClicked();//点击Join a group获取搜索框里的群号并加入群聊

private:
	Ui::AddClass ui;
};
