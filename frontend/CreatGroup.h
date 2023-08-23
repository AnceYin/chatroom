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
	void onItemClicked(QListWidgetItem* item);//点击各行发生的事件
	void SearchClicked();//点击搜索按钮发生的事件
	void onDataReceived(const QByteArray& data);//接收消息

private:
	Ui::CreatGroupClass ui;
	TcpSingleton* m_tcpConn;
};
