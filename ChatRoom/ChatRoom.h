#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ChatRoom.h"

class ChatRoom : public QMainWindow
{
    Q_OBJECT

public:
    ChatRoom(QWidget *parent = nullptr);
    ~ChatRoom();
    void ShowMessage();//显示消息

private slots:
    void SerachPushButtonClicked();//点击serach按钮执行查找消息的操作
    void LogOutPushButtonClicked();//点击Log out登出
    void SendPushButtonClicked();//点击Send发送消息
    void AddPushButtonClicked();//点击add跳转到add页面
    void MessageClicked();//点击消息显示聊天记录

private:
    Ui::ChatRoomClass ui;
};
