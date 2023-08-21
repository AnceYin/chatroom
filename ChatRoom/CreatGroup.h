#pragma once

#include <QMainWindow>
#include "ui_CreatGroup.h"
#include "TcpConnection.h"
#include "serialize/DataStream.h"
#include "serialize/Serializable.h"
#include <iostream>

class CreatGroup : public QMainWindow
{
	Q_OBJECT

public:
	CreatGroup(QWidget *parent = nullptr);
	~CreatGroup();

private slots:
	void onItemClicked(QListWidgetItem* item);//������з������¼�
	void SearchClicked();//���������ť�������¼�
	void onDataReceived(const QByteArray& data);//������Ϣ

private:
	Ui::CreatGroupClass ui;
	TcpSingleton* m_tcpConn;
};
