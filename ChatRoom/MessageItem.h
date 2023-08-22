#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ChatRoom.h"

// �Զ���� QListWidgetItem ���࣬���ڳ�����Ϣ��ͷ����Ϣ
class MessageItem : public QListWidgetItem {
public:
    MessageItem(const QString& message, const QPixmap& avatar)
        : QListWidgetItem(), m_message(message), m_avatar(avatar) {
    }

    QString message() const {
        return m_message;
    }

    QPixmap avatar() const {
        return m_avatar;
    }

private:
    QString m_message;
    QPixmap m_avatar;
};