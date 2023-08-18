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
	void CreatPushButtonClicked();//��ȡȺ��ͷ�������

private:
	Ui::AddClass ui;
};
