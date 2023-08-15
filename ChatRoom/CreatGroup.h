#pragma once

#include <QMainWindow>
#include "ui_CreatGroup.h"

class CreatGroup : public QMainWindow
{
	Q_OBJECT

public:
	CreatGroup(QWidget *parent = nullptr);
	~CreatGroup();

private slots:
	void ReturnPushButtonClicked();//返回上级页面
	void CreatPushButtonClicked();//获取群聊头像和名称

private:
	Ui::CreatGroupClass ui;
};
