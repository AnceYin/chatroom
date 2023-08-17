#include "ChatRoom.h"
#include "CreatGroup.h"
#include <QtWidgets/QApplication>
#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTcpSocket>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChatRoom w;
    CreatGroup c;
    c.show();
    //w.show();
    return a.exec();
}
