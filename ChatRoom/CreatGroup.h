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
	void ReturnPushButtonClicked();//�����ϼ�ҳ��
	void CreatPushButtonClicked();//��ȡȺ��ͷ�������

private:
	Ui::CreatGroupClass ui;
};
