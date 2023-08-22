#include "ChatRoom.h"
#include "Login.h"
#include "CreatGroup.h"
#include"NewContacts.h"
#include <QtWidgets/QApplication>
#include <QApplication>
#include <QStackedWidget>


int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    ChatRoom c;
    Login l;
    l.show();
    //c.show();
    return a.exec();
}
