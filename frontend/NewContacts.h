#pragma once

#include <QMainWindow>
#include "ui_NewContacts.h"

class NewContacts : public QMainWindow
{
	Q_OBJECT

public:
	NewContacts(QWidget *parent = nullptr);
	~NewContacts();
	void ShowMessage();//��ѯ���ݿ��ȡ��Ϣ(˽����Ϣ��Ⱥ����Ϣ)����ʾ��Ϣ
	void ShowNewContacts();//���ܷ����������ĺ������벢��ʾ

private slots:
	void ReturnPushButtonClicked();//�����ϼ�ҳ��
	void AcceptPushButtonClicked();//���Accept��ťִ�еĲ���
	void RefusePushButtonClicked();//���Accept��ťִ�еĲ���
	void MessageClicked();//�����Ϣ��ʾ�����¼

private:
	Ui::NewContactsClass ui;
};
