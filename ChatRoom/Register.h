#pragma once

#include <QMainWindow>
#include "ui_Register.h"

class Register : public QMainWindow
{
	Q_OBJECT

public:
	Register(QWidget *parent = nullptr);
	~Register();

private slots:
	void RegisterPushButtonClicked();//���ע�ᰴť��ѯ���ݿ��û����Ƿ����
	void SignInClicked();//���Sign in���õĲۺ���

private:
	Ui::RegisterClass ui;
};
