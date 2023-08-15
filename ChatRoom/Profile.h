#pragma once

#include <QMainWindow>
#include "ui_Profile.h"

class Profile : public QMainWindow
{
	Q_OBJECT

public:
	Profile(QWidget *parent = nullptr);
	~Profile();

private slots:
	void ReturnPushButtonClicked();//点击返回按钮调用的槽函数(返回上级页面）
	void EditClicked();//点击Edit按钮获取头像，用户名，密码并更改用户名和密码，头像上传数据库

private:
	Ui::ProfileClass ui;
};
