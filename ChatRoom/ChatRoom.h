#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ChatRoom.h"
#include <QtNetwork>
#include<QMessageBox>
#include <QListWidgetItem>

class ChatRoom : public QMainWindow
{
    Q_OBJECT

public:
    ChatRoom(QWidget *parent = nullptr);
    ~ChatRoom();
    void ShowMessage();//显示消息
    void addChatMessage(const QString& avatarPath, const QString& message,int k);

private slots:
    void SerachPushButtonClicked();//点击serach按钮执行查找消息的操作
    void LogOutPushButtonClicked();//点击Log out登出
    void SendPushButtonClicked();//点击Send发送消息
    void read_ServerData();//接受服务器发来的消息
    void MessageClicked(QListWidgetItem* item);//点击消息加载聊天记录

private:
    Ui::ChatRoomClass ui;
    QTcpSocket* tcpSocket;
    bool isConnected=false;
    QString CurrentContact;
    QString SendMessage;
    QString ReceiveMessage;
};




