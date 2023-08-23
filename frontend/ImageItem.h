#pragma 

#include <QtWidgets/QMainWindow>
#include "ui_ChatRoom.h"


// �Զ���� QListWidgetItem ���࣬���ڳ���ͼƬ��Ϣ
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
