#include "Add.h"



Add::Add(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.lineEdit->setPlaceholderText(QString::fromLocal8Bit("Group Name?"));
}

Add::~Add()
{}

void Add::CreatPushButtonClicked()
{
	//获取文本框里面的群聊名称和群头像
	

}