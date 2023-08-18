#pragma once

#include <QMainWindow>
#include "ui_CreatGroup.h"

class CreatGroup : public QMainWindow
{
	Q_OBJECT

public:
	CreatGroup(QWidget *parent = nullptr);
	~CreatGroup();

private slots:
	void onItemClicked(QListWidgetItem* item);//点击各行发生的事件

private:
	Ui::CreatGroupClass ui;
};
