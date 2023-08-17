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

// 自定义的数据模型类
//class ChatModel : public QAbstractListModel {
//    Q_OBJECT
//public:
//    // 聊天消息结构体
//    struct ChatMessage {
//        QString sender;
//        QString message;
//        QPixmap avatar;
//    };
//
//    explicit ChatModel(QObject* parent = nullptr)
//        : QAbstractListModel(parent) {}
//
//    int rowCount(const QModelIndex& parent = QModelIndex()) const override {
//        Q_UNUSED(parent)
//            return m_messages.size();
//    }
//
//    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override {
//        if (!index.isValid() || index.row() >= m_messages.size()) {
//            return QVariant();
//        }
//
//        if (role == Qt::UserRole) {
//            return QVariant::fromValue(m_messages[index.row()]);
//        }
//
//        return QVariant();
//    }
//
//    void addMessage(const ChatMessage& message) {
//        beginInsertRows(QModelIndex(), m_messages.size(), m_messages.size());
//        m_messages.append(message);
//        endInsertRows();
//    }
//
//private:
//    QVector<ChatMessage> m_messages;
//};
//
//// 自定义的委托类
//class ChatDelegate : public QStyledItemDelegate {
//    Q_OBJECT
//public:
//    explicit ChatDelegate(QObject* parent = nullptr)
//        : QStyledItemDelegate(parent) {}
//
//    QSize sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const override {
//        Q_UNUSED(option)
//
//            if (!index.isValid()) {
//                return QStyledItemDelegate::sizeHint(option, index);
//            }
//
//        const ChatModel::ChatMessage message = index.data(Qt::UserRole).value<ChatModel::ChatMessage>();
//        QPixmap avatar = message.avatar;
//
//        // 根据需求设置头像大小和边距
//        int avatarSize = 40;
//        int margin = 10;
//
//        return QSize(avatarSize + margin * 2, qMax(avatarSize, option.fontMetrics.height()) + margin * 2);
//    }
//
//    void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const override {
//        if (!index.isValid()) {
//            QStyledItemDelegate::paint(painter, option, index);
//            return;
//        }
//
//        const int avatarSize = 40;
//        const int margin = 10;
//        const int padding = 5;
//        const ChatModel::ChatMessage message = index.data(Qt::UserRole).value<ChatModel::ChatMessage>();
//        QPixmap avatar = message.avatar;
//
//        QRect avatarRect(option.rect.topLeft() + QPoint(margin, margin), QSize(avatarSize, avatarSize));
//        QRect textRect(option.rect.topLeft() + QPoint(margin + avatarSize + padding, margin),
//            QSize(option.rect.width() - margin * 2 - avatarSize - padding * 2, option.rect.height() - margin * 2));
//
//        // 绘制头像
//        painter->drawPixmap(avatarRect, avatar.scaled(avatarRect.size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
//
//        // 绘制消息文本
//        painter->drawText(textRect, Qt::TextWordWrap | Qt::AlignLeft | Qt::AlignTop, message.message);
//    }
//};
//
//// 主窗口类
//class MainWindow : public QMainWindow {
//    Q_OBJECT
//public:
//    explicit MainWindow(QWidget* parent = nullptr)
//        : QMainWindow(parent) {
//        // 初始化数据模型
//        m_chatModel = new ChatModel(this);
//
//        // 初始化列表视图
//        m_listView = new QListView(this);
//        m_listView->setModel(m_chatModel);
//
//        // 使用自定义委托
//        m_chatDelegate = new ChatDelegate(this);
//        m_listView->setItemDelegate(m_chatDelegate);
//
//        // 设置布局
//        QVBoxLayout* layout = new QVBoxLayout;
//        layout->addWidget(m_listView);
//
//        QWidget* centralWidget = new QWidget(this);
//        centralWidget->setLayout(layout);
//        setCentralWidget(centralWidget);
//    }
//
//public slots:
//    // 发送按钮的点击事件槽函数
//    void on_sendButton_clicked() {
//        QString sender = "Sender";
//        QString message = ui->lineEdit->text();
//        QPixmap avatar(":/path/to/avatar.png");
//
//        ChatModel::ChatMessage chatMessage;
//        chatMessage.sender = sender;
//        chatMessage.message = message;
//        chatMessage.avatar = avatar;
//
//        // 添加聊天消息到数据模型
//        m_chatModel->addMessage(chatMessage);
//
//        // 清空输入框
//        ui->lineEdit->clear();
//    }
//
//private:
//    ChatModel* m_chatModel;
//    QListView* m_listView;
//    ChatDelegate* m_chatDelegate;
//};
