#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ChatRoom.h"

// 自定义的 QListWidgetItem 子类，用于承载消息和头像信息
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