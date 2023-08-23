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
	void ReturnPushButtonClicked();//������ذ�ť���õĲۺ���(�����ϼ�ҳ�棩
	void EditClicked();//���Edit��ť��ȡͷ���û��������벢�����û��������룬ͷ���ϴ����ݿ�

private:
	Ui::ProfileClass ui;
};
