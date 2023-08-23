#pragma once
#include <iostream>
#include "../net.cpp"
#include "MessageHandler.h"

class MessageHandlerIndustry
{
public:
	MessageHandlerIndustry(int msgType, int msgSize, std::string msg) : msgType(msgType), messageSize(msgSize), msg(msg) {};
	MessageHandler* CreateMessageHandler();
	~MessageHandlerIndustry();
private:
	int msgType;
	int messageSize;
	std::string msg;
};