#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ChatRoom.h"

class ChatRoom : public QMainWindow
{
    Q_OBJECT

public:
    ChatRoom(QWidget *parent = nullptr);
    ~ChatRoom();
    void ShowMessage();//��ʾ��Ϣ

private slots:
    void SerachPushButtonClicked();//���serach��ťִ�в�����Ϣ�Ĳ���
    void LogOutPushButtonClicked();//���Log out�ǳ�
    void SendPushButtonClicked();//���Send������Ϣ
    void AddPushButtonClicked();//���add��ת��addҳ��
    void MessageClicked();//�����Ϣ��ʾ�����¼

private:
    Ui::ChatRoomClass ui;
};

