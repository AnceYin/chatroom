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
	void ReturnPushButtonClicked();//�����ϼ�Ŀ¼
	void NewContactPushButtonClicked();//���New Contact��Ӻ���
	void CreatAGroupPushButtonClicked();//���Creat a group��ת��Creating a groupҳ��
	void SerachPushButtonClicked();//���serach�����û���Ⱥ��
	void JoinAGroupPushButtonClicked();//���Join a group��ȡ���������Ⱥ�Ų�����Ⱥ��

private:
	Ui::AddClass ui;
};
