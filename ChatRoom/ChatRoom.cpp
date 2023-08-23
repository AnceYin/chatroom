#include "ChatRoom.h"
#include <qboxlayout.h>
#include"MessageItem.h"
#include"ImageItem.h"
#include"Add.h"

ChatRoom::ChatRoom(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    m_tcpConn = TcpSingleton::instance();
    // ���ͳ�ʼ������ ����09|team_id1|team_id2.....
     QString msgIni = "09|" + user_id;
     m_tcpConn->sendData(msgIni.toLatin1(), msgIni.size());

    // bool state = m_tcpConn->waitForConnected(1000);
    /*if (state) {
        isConnected = true;
        QMessageBox::information(NULL, "Title", "success");
        connect(tcpSocket, &QTcpSocket::readyRead, this, &ChatRoom::read_ServerData);
    }
    else {
        QMessageBox::warning(this, "Title", "fail");
    }*/
    connect(m_tcpConn, &TcpSingleton::dataReceived, this, &ChatRoom::onDataReceived);
    ShowMessage();
}

ChatRoom::~ChatRoom()
{}

void ChatRoom::SerachPushButtonClicked()
{
    QFile file("://Contacts.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        // ��ȡ�����¼
        while (!stream.atEnd()) {
            QString line = stream.readLine();
            if (ui.Serach_LineEdit->text() == line) {
                ui.listWidget->clear();
                QString filePath = "://chatlogs/" + line + ".txt";
                QFile file(filePath);
                if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                    QTextStream stream(&file);
                    //��ȡ�����¼
                    int k;
                    QString message, Path;
                    while (!stream.atEnd()) {
                        QString line = stream.readLine();
                        QStringList parts = line.split(':');
                        Path = parts[0];
                        message = parts[1];
                        k = parts[2].toInt();
                        addChatMessage(Path, message, k);
                    }
                    file.close();
                }
                else {
                    qDebug() << "�޷����ļ���";
                }
            }
        }
        file.close();
    }
    else {
        qDebug() << "�޷����ļ���";
    }
}

void ChatRoom::LogOutPushButtonClicked()
{
    QString str = "10";
    m_tcpConn->sendData(str.toLatin1(), str.size());
    this->close();
}

void ChatRoom::ShowMessage()
{
    QStringList messages;
    QFile file("://Contacts.txt");//�����ϵ��ʱ���ɵ���ϵ���ĵ�(ֻ������ϵ��)��ÿ����ϵ����һ�������Ĵ������¼���ĵ�(��Addҳ����Ӻ���ʱ����)
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        //��ȡ�����¼
        while (!stream.atEnd()) {
            QString line = stream.readLine();
            messages << line;
        }
        file.close();
    }
    else {
        qDebug() << "�޷����ļ���";
    }

    foreach(const QString & message, messages) {
        QString AvatarFilePath = "://avatar/" + message + ".png";//�����ϵ��ʱ�����û�������ĸ���ɵ�ͷ���ĵ�(ֻ����ͷ��)(��Addҳ����Ӻ���ʱ����)
        QPixmap avatar(AvatarFilePath);
        MessageItem* item = new MessageItem(message, avatar);

        // ʹ�� QListWidgetItem �� setIcon() ��������ͷ��
        item->setIcon(QIcon(avatar));

        // ʹ�� QListWidgetItem �� setText() ����������Ϣ����
        item->setText(message);

        ui.listWidget_MessageQueue->addItem(item);
    }
    // ����һ��ͼƬ
    QPixmap image("://img/add.png");

    // ����һ�� ImageItem ���󣬲�����ͼƬ
    ImageItem* item = new ImageItem(image);

    // ʹ�� QListWidgetItem �� setSizeHint() ����������Ĵ�СΪͼƬ�Ĵ�С
    item->setSizeHint(QSize(20, 20));

    // ���� QListWidgetItem �Ķ��뷽ʽΪ���ж���
    item->setTextAlignment(Qt::AlignCenter);

    // ʹ�� QListWidgetItem �� setIcon() ��������ͼƬ
    item->setIcon(QIcon(image));

    // ��ͼƬ����ӵ���Ϣ����
    ui.listWidget_MessageQueue->addItem(item);

    // ���� itemClicked �ź���ۺ���������Ӧ�����Ϣ���¼�
    connect(ui.listWidget_MessageQueue, &QListWidget::itemClicked, this, &ChatRoom::MessageClicked);
}

// ��06|user_id|team_id|content
//   09|team_id|team_id...
void ChatRoom::onDataReceived(const QByteArray& data)
{
    QString receivedData = QString::fromUtf8(data);
    // �����ж�ǰ�����ַ���06��team����msg�����ǳ�ʼ��09��TEAM_INIT������ͬ�߼�����
    if (receivedData[0] == '0' && receivedData[1] == '9') {
        ui.listWidget_MessageQueue->clear();
        // ����һ��ͼƬ
        QPixmap image("://img/add.png");

        // ����һ�� ImageItem ���󣬲�����ͼƬ
        ImageItem* item = new ImageItem(image);

        // ʹ�� QListWidgetItem �� setSizeHint() ����������Ĵ�СΪͼƬ�Ĵ�С
        item->setSizeHint(QSize(20, 20));

        // ���� QListWidgetItem �Ķ��뷽ʽΪ���ж���
        item->setTextAlignment(Qt::AlignCenter);

        // ʹ�� QListWidgetItem �� setIcon() ��������ͼƬ
        item->setIcon(QIcon(image));

        // ��ͼƬ����ӵ���Ϣ����
        ui.listWidget_MessageQueue->addItem(item);
        receivedData.remove(0, 3);
        QStringList team_idList = receivedData.split("|");
        for (int i = 0; i < team_idList.size(); i++) {
            Group g;
            g.id = team_idList[i];
            groups.push_back(g);

            // ������ǩ
            QListWidgetItem* item = new QListWidgetItem(g.id);

            // ����ǩ��ӵ� QListWidget
            ui.listWidget_MessageQueue->addItem(item);
        }

    }
    else if (receivedData[0] == '0' && receivedData[1] == '6') {
        // 06|user_id|team_id|msg
        // ������Ϣ
        QStringList messageParts = receivedData.split("|");
        if (messageParts.size() >= 4) {
            QString messageType = messageParts[0];
            QString userId = messageParts[1];
            QString teamId = messageParts[2];
            QString messageContent = messageParts[3];

            if (user_id == userId) return;
            // �� groups �в���ƥ�����
            bool groupFound = false;
            for (int i = 0; i < groups.size(); i++) {
                if (groups[i].id == teamId) {
                    // �ҵ�ƥ����飬����Ϣ���뵽����� chatMessages ��
                    ChatMessage chatMessage;
                    chatMessage.sender_id = userId;
                    chatMessage.message = messageContent;
                    chatMessage.timestamp = QDateTime::currentDateTime();
                    groups[i].chatMessages.push_back(chatMessage);
                    
                    if (teamId == team_id_current) {
                        addChatMessage("", "user:" + userId, 1);
                        addChatMessage("", messageContent, 1);
                    }
                    
                    groupFound = true;
                    break;
                }
            }

            if (!groupFound) {
                // δ�ҵ�ƥ����飬�����µ��鲢���뵽 groups ��
                Group newGroup;
                newGroup.name = teamId;  // ������������ teamId ��ͬ
                newGroup.id = teamId;
                ChatMessage chatMessage;
                chatMessage.sender_id = userId;
                chatMessage.message = messageContent;
                chatMessage.timestamp = QDateTime::currentDateTime();
                newGroup.chatMessages.push_back(chatMessage);
                groups.push_back(newGroup);
            }
        }
        ////���涨�и��ַ���
        //QString AvatarFilePath = "://avatar/" + CurrentContact + ".png";
        //addChatMessage(AvatarFilePath, receivedData, -1);
        //QString filePath = "://chatlogs/" + CurrentContact + ".txt"; // ����Ψһ��ʶ�������ļ�·��
        //QFile file(filePath);
        //if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        //    QTextStream stream(&file);
        //    // ������д�������¼
        //    QString logEntry = QString("%1: %2: %3").arg(AvatarFilePath, SendMessage, "-1");
        //    stream << logEntry << endl;
        //    file.close();
        //}

    }
}

void ChatRoom::SendPushButtonClicked()
{
    // 06|user_id|team_id|str
    if (isConnected) {
        if (ui.Message->toPlainText() == "") {
            QMessageBox::information(NULL, "Title", "The text box should have data!");
            return;
        }
        SendMessage = ui.Message->toPlainText();

        // ��ȥteamid
        QString Msg = "06|" + user_id + "|" + team_id_current + "|" + SendMessage;
       
        //���涨����ַ���
        m_tcpConn->sendData(Msg.toLatin1(), Msg.size());

        ChatMessage chatMessage;
        chatMessage.sender_id = user_id;
        chatMessage.message = SendMessage;
        chatMessage.timestamp = QDateTime::currentDateTime();
        findGroupByTeamId(team_id_current, groups)->chatMessages.push_back(chatMessage);

        addChatMessage("", "user:" + user_id, -1);
        addChatMessage("", ui.Message->toPlainText(), -1);
        //QString AvatarFilePath = "://avatar/self.png";//��¼�ͻ����û���ͷ��
        //addChatMessage(AvatarFilePath, ui.Message->toPlainText(),1);//1�����ǿͻ��˷��͵����ݣ�-1������ܵ�����
        //// ������ϵ�˵�Ψһ��ʶ�����û���
        //QString filePath = "://chatlogs/" + CurrentContact + ".txt"; // ����Ψһ��ʶ�������ļ�·��
        //QFile file(filePath);
        //if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        //    QTextStream stream(&file);
        //    // ������д�������¼
        //    QString logEntry = QString("%1: %2: %3").arg(AvatarFilePath, SendMessage,"1");
        //    stream << logEntry << endl;
        //    file.close();
        //}
    }
    else {
        QMessageBox::warning(this, "error", "Not connected to the server!");
    }
}

void ChatRoom::addChatMessage(const QString& avatarPath, const QString& message,int k) {
    // ���� QListWidgetItem
    QListWidgetItem* item = new QListWidgetItem;

    // ���� QWidget ��Ϊ QListWidgetItem ��С����
    QWidget* widget = new QWidget;

    // ����ͷ�� QLabel
    QLabel* avatarLabel = new QLabel;
    QPixmap avatarPixmap(avatarPath);
    // ������Ҫ����ͷ��Ĵ�С
    QPixmap scaledPixmap = avatarPixmap.scaled(20,20);
    avatarLabel->setPixmap(scaledPixmap);
    // ������Ϣ QLabel
    QLabel* messageLabel = new QLabel;
    messageLabel->setText(message);

    // ��ͷ�� QLabel ����Ϣ QLabel ������ˮƽ������
    QHBoxLayout* layout = new QHBoxLayout(widget);
    if (k == 1) {
        //layout->addWidget(avatarLabel);
        layout->addWidget(messageLabel);
        layout->setAlignment(Qt::AlignLeft);
    }
    else {
        layout->addWidget(messageLabel);
        //layout->addWidget(avatarLabel);
        layout->setAlignment(Qt::AlignRight);
    }
    layout->setSpacing(5); // ΪС�������һЩ���

    // ��С��������Ϊ QListWidgetItem ��С����
    item->setSizeHint(widget->sizeHint());
    ui.listWidget->addItem(item);
    ui.listWidget->setItemWidget(item, widget);
    ui.listWidget->scrollToBottom();
}

void ChatRoom::MessageClicked(QListWidgetItem* item)
{
    // dynamic_cast<MessageItem*>(item) != nullptr
    if (!item->text().isEmpty())
    {
        team_id_current = item->text();
        ui.listWidget->clear();
        for (int i = 0; i < groups.size(); i++) {
            if (groups[i].id == team_id_current) {
                for (auto& c : groups[i].chatMessages) {
                    int k = 1;
                    if (c.sender_id == user_id) k = -1;
                    addChatMessage("", "user:" + c.sender_id, k);
                    addChatMessage("", c.message, k);
                }
                break;
            }
        }
        
        //MessageItem* messageItem = dynamic_cast<MessageItem*>(item);
        //QString message = messageItem->message();
        //QPixmap avatar = messageItem->avatar();

        //// ������Ϣ��ͷ����Ϣ��ȡ��Ӧ�������¼������ʾ�ڽ�����
        //ui.listWidget->clear();
        //CurrentContact = message;
        //QString filePath = "://chatlogs/" + CurrentContact + ".txt";
        //QFile file(filePath);
        //if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        //    QTextStream stream(&file);
        //    //��ȡ�����¼
        //    int k;
        //    QString message,Path;
        //    while (!stream.atEnd()) {
        //        QString line = stream.readLine();
        //        QStringList parts = line.split(':');
        //        Path = parts[0];
        //        message = parts[1];
        //        k = parts[2].toInt();
        //        addChatMessage(Path, message, k);
        //    }
        //    file.close();
        //}
        //else {
        //    qDebug() << "�޷����ļ���";
        //}
    }
    else {
        CreatGroup* c = new CreatGroup();
        c->show();
    }
}

Group* ChatRoom::findGroupByTeamId(const QString& teamId, QVector<Group>& groups)
{
    for (int i = 0; i < groups.size(); i++) {
        if (groups[i].id == teamId) {
            return &groups[i];
        }
    }
    return nullptr;  // ���δ�ҵ�ƥ����飬�򷵻� nullptr
}