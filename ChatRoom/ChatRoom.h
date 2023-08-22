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
    void ShowMessage();//��ʾ��Ϣ
    void addChatMessage(const QString& avatarPath, const QString& message,int k);

private slots:
    void SerachPushButtonClicked();//���serach��ťִ�в�����Ϣ�Ĳ���
    void LogOutPushButtonClicked();//���Log out�ǳ�
    void SendPushButtonClicked();//���Send������Ϣ
    void read_ServerData();//���ܷ�������������Ϣ
    void MessageClicked(QListWidgetItem* item);//�����Ϣ���������¼

private:
    Ui::ChatRoomClass ui;
    QTcpSocket* tcpSocket;
    bool isConnected=false;
    QString CurrentContact;
    QString SendMessage;
    QString ReceiveMessage;
};




