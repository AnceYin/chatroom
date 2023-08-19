#pragma once
#include <iostream>
#include "../net.cpp"
#include "MessageHandler.h"

// �������ݴ����๤����
class MessageHandlerIndustry
{
public:
	MessageHandlerIndustry(std::string msgType, int msgSize, std::string msg) : msgType(msgType), messageSize(msgSize) msg(msg) {};
	MessageHandler* CreateMessageHandler();
	~MessageHandlerIndustry();
private:
	std::string msgType;
	int messageSize;
	std::string msg;
};




