#pragma 

#include <QtWidgets/QMainWindow>
#include "ui_ChatRoom.h"


// 自定义的 QListWidgetItem 子类，用于承载图片信息
class ImageItem : public QListWidgetItem {
public:
    ImageItem(const QPixmap& image)
        : QListWidgetItem(), m_image(image) {
    }

    QPixmap image() const {
        return m_image;
    }

private:
    QPixmap m_image;
};
