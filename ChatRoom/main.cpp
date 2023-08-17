#include "ChatRoom.h"
#include"Login.h"
#include"NewContacts.h"
#include <QtWidgets/QApplication>
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChatRoom w;
    w.show();
    return a.exec();
}
