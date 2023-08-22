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
    // 发送初始化报文 返回09|team_id1|team_id2.....
    // QString msgIni = "09|" + user_id;
    // m_tcpConn->sendData(msgIni.toLatin1(), msgIni.size());

    ui.Message->setText(user_id);

    //bool state = m_tcpConn->waitForConnected(1000);
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
        //读取聊天记录
        while (!stream.atEnd()) {
            QString line = stream.readLine();
            if (ui.Serach_LineEdit->text() == line) {
                ui.listWidget->clear();
                QString filePath = "://chatlogs/" + line + ".txt";
                QFile file(filePath);
                if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                    QTextStream stream(&file);
                    //读取聊天记录
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
                    qDebug() << "无法打开文件：";
                }
            }
        }
        file.close();
    }
    else {
        qDebug() << "无法打开文件：";
    }
}

void ChatRoom::LogOutPushButtonClicked()
{
    this->close();
}

void ChatRoom::ShowMessage()
{
    QStringList messages;
    QFile file("://Contacts.txt");//添加联系人时生成的联系人文档(只保存联系人)且每个联系人有一个单独的存聊天记录的文档(在Add页面添加好友时创建)
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        //读取聊天记录
        while (!stream.atEnd()) {
            QString line = stream.readLine();
            messages << line;
        }
        file.close();
    }
    else {
        qDebug() << "无法打开文件：";
    }

    foreach(const QString & message, messages) {
        QString AvatarFilePath = "://avatar/" + message + ".png";//添加联系人时根据用户名首字母生成的头像文档(只保存头像)(在Add页面添加好友时创建)
        QPixmap avatar(AvatarFilePath);
        MessageItem* item = new MessageItem(message, avatar);

        // 使用 QListWidgetItem 的 setIcon() 方法设置头像
        item->setIcon(QIcon(avatar));

        // 使用 QListWidgetItem 的 setText() 方法设置消息内容
        item->setText(message);

        ui.listWidget_MessageQueue->addItem(item);
    }
    // 创建一张图片
    QPixmap image("://img/add.png");

    // 创建一个 ImageItem 对象，并设置图片
    ImageItem* item = new ImageItem(image);

    // 使用 QListWidgetItem 的 setSizeHint() 方法设置项的大小为图片的大小
    item->setSizeHint(QSize(20, 20));

    // 设置 QListWidgetItem 的对齐方式为居中对齐
    item->setTextAlignment(Qt::AlignCenter);

    // 使用 QListWidgetItem 的 setIcon() 方法设置图片
    item->setIcon(QIcon(image));

    // 将图片项添加到消息队列
    ui.listWidget_MessageQueue->addItem(item);

    // 连接 itemClicked 信号与槽函数，以响应点击消息的事件
    connect(ui.listWidget_MessageQueue, &QListWidget::itemClicked, this, &ChatRoom::MessageClicked);
}

void ChatRoom::onDataReceived(const QByteArray& data)
{
    QString receivedData = QString::fromUtf8(data);
    // 首先判断前两个字符是06（team——msg）还是初始化09（TEAM_INIT）按不同逻辑处理
    
    //按规定切割字符串
    QString AvatarFilePath = "://avatar/" + CurrentContact + ".png";
    addChatMessage(AvatarFilePath, receivedData,-1);
    QString filePath = "://chatlogs/" + CurrentContact + ".txt"; // 根据唯一标识符构建文件路径
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        // 在这里写入聊天记录
        QString logEntry = QString("%1: %2: %3").arg(AvatarFilePath, SendMessage, "-1");
        stream << logEntry << endl;
        file.close();
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

        // 拿去teamid

        QString team_id = "111111111111111111111111111111";
        QString Msg = "06|" + user_id + "|" + team_id + "|" + SendMessage;


        // ------------------------------------------------
         
       
        //按规定组合字符串
        m_tcpConn->sendData(Msg.toLatin1(), Msg.size());
        QString AvatarFilePath = "://avatar/self.png";//登录客户端用户的头像
        addChatMessage(AvatarFilePath, ui.Message->toPlainText(),1);//1代表是客户端发送的数据，-1代表接受的数据
        // 假设联系人的唯一标识符是用户名
        QString filePath = "://chatlogs/" + CurrentContact + ".txt"; // 根据唯一标识符构建文件路径
        QFile file(filePath);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream stream(&file);
            // 在这里写入聊天记录
            QString logEntry = QString("%1: %2: %3").arg(AvatarFilePath, SendMessage,"1");
            stream << logEntry << endl;
            file.close();
        }
    }
    else {
        QMessageBox::warning(this, "error", "Not connected to the server!");
    }
}

void ChatRoom::addChatMessage(const QString& avatarPath, const QString& message,int k) {
    // 创建 QListWidgetItem
    QListWidgetItem* item = new QListWidgetItem;

    // 创建 QWidget 作为 QListWidgetItem 的小部件
    QWidget* widget = new QWidget;

    // 创建头像 QLabel
    QLabel* avatarLabel = new QLabel;
    QPixmap avatarPixmap(avatarPath);
    // 根据需要设置头像的大小
    QPixmap scaledPixmap = avatarPixmap.scaled(20,20);
    avatarLabel->setPixmap(scaledPixmap);
    // 创建消息 QLabel
    QLabel* messageLabel = new QLabel;
    messageLabel->setText(message);

    // 将头像 QLabel 和消息 QLabel 放置在水平布局中
    QHBoxLayout* layout = new QHBoxLayout(widget);
    if (k == 1) {
        layout->addWidget(avatarLabel);
        layout->addWidget(messageLabel);
        layout->setAlignment(Qt::AlignLeft);
    }
    else {
        layout->addWidget(messageLabel);
        layout->addWidget(avatarLabel);
        layout->setAlignment(Qt::AlignRight);
    }
    layout->setSpacing(5); // 为小部件添加一些间距

    // 将小部件设置为 QListWidgetItem 的小部件
    item->setSizeHint(widget->sizeHint());
    ui.listWidget->addItem(item);
    ui.listWidget->setItemWidget(item, widget);
    ui.listWidget->scrollToBottom();
}

void ChatRoom::MessageClicked(QListWidgetItem* item)
{
    if (dynamic_cast<MessageItem*>(item) != nullptr)
    {
        MessageItem* messageItem = dynamic_cast<MessageItem*>(item);
        QString message = messageItem->message();
        QPixmap avatar = messageItem->avatar();

        // 根据消息和头像信息获取对应的聊天记录，并显示在界面中
        ui.listWidget->clear();
        CurrentContact = message;
        QString filePath = "://chatlogs/" + CurrentContact + ".txt";
        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream stream(&file);
            //读取聊天记录
            int k;
            QString message,Path;
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
            qDebug() << "无法打开文件：";
        }
    }
    else {
        this->close();
        Add *w=new Add();
        w->show();//打开Add页面
    }
}
