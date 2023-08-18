#include "ChatRoom.h"
#include "Login.h"
#include"NewContacts.h"
#include <QtWidgets/QApplication>
#include <QApplication>


int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    ChatRoom w;
    Login l;
    l.show();
    return a.exec();
}
