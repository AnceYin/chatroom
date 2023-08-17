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

// �Զ��������ģ����
//class ChatModel : public QAbstractListModel {
//    Q_OBJECT
//public:
//    // ������Ϣ�ṹ��
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
//// �Զ����ί����
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
//        // ������������ͷ���С�ͱ߾�
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
//        // ����ͷ��
//        painter->drawPixmap(avatarRect, avatar.scaled(avatarRect.size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
//
//        // ������Ϣ�ı�
//        painter->drawText(textRect, Qt::TextWordWrap | Qt::AlignLeft | Qt::AlignTop, message.message);
//    }
//};
//
//// ��������
//class MainWindow : public QMainWindow {
//    Q_OBJECT
//public:
//    explicit MainWindow(QWidget* parent = nullptr)
//        : QMainWindow(parent) {
//        // ��ʼ������ģ��
//        m_chatModel = new ChatModel(this);
//
//        // ��ʼ���б���ͼ
//        m_listView = new QListView(this);
//        m_listView->setModel(m_chatModel);
//
//        // ʹ���Զ���ί��
//        m_chatDelegate = new ChatDelegate(this);
//        m_listView->setItemDelegate(m_chatDelegate);
//
//        // ���ò���
//        QVBoxLayout* layout = new QVBoxLayout;
//        layout->addWidget(m_listView);
//
//        QWidget* centralWidget = new QWidget(this);
//        centralWidget->setLayout(layout);
//        setCentralWidget(centralWidget);
//    }
//
//public slots:
//    // ���Ͱ�ť�ĵ���¼��ۺ���
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
//        // ���������Ϣ������ģ��
//        m_chatModel->addMessage(chatMessage);
//
//        // ��������
//        ui->lineEdit->clear();
//    }
//
//private:
//    ChatModel* m_chatModel;
//    QListView* m_listView;
//    ChatDelegate* m_chatDelegate;
//};
