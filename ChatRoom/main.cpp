#include "ChatRoom.h"
#include "Login.h"
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

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    ChatRoom w;
    Login l;
    l.show();
    return a.exec();
}
