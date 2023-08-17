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
	void CreatPushButtonClicked();//获取群聊头像和名称

private:
	Ui::AddClass ui;
};
