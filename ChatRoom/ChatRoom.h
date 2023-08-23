#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ChatRoom.h"
#include <QtNetwork>
#include<QMessageBox>
#include <QListWidgetItem>
#include <qvector>
#include "TcpConnection.h"
#include "Login.h"
#include "CreatGroup.h"
extern QString user_id;

struct ChatMessage {
    QString sender_id;
    QString message;
    QDateTime timestamp;
};

struct Group {
    QString name;
    QString id;
    QVector<ChatMessage> chatMessages;
};

class ChatRoom : public QMainWindow
{
    Q_OBJECT

public:
    ChatRoom(QWidget *parent = nullptr);
    ~ChatRoom();
    void ShowMessage();//��ʾ��Ϣ
    void addChatMessage(const QString& avatarPath, const QString& message,int k);
    Group* findGroupByTeamId(const QString& teamId, QVector<Group>& groups);

private slots:
    void SerachPushButtonClicked();//���serach��ťִ�в�����Ϣ�Ĳ���
    void LogOutPushButtonClicked();//���Log out�ǳ�
    void SendPushButtonClicked();//���Send������Ϣ
    //void read_ServerData();//���ܷ�������������Ϣ
    void MessageClicked(QListWidgetItem* item);//�����Ϣ���������¼
    // 数据接受
    void onDataReceived(const QByteArray& data);

private:
    Ui::ChatRoomClass ui;
    TcpSingleton* m_tcpConn;
    bool isConnected=true;
    QString CurrentContact;
    QString SendMessage;
    QString ReceiveMessage;
    // team_id, user_id, content
    QVector<Group> groups;
    QString team_id_current = "";
};






