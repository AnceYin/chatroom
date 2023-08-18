#pragma once
#include <iostream>
#include "../net.cpp"
#include "../serialize/DataStream.h"
#include "../serialize/Serializable.h"
#include "MessageHandler.h"

using namespace yazi::serialize;

// �������ݴ����๤����
class MessageHandlerIndustry
{
public:
	MessageHandlerIndustry(int msgType, int msgSize, DataStream ds) : messageType(msgType), messageSize(msgSize), ds(ds) {};
	MessageHandler* CreateMessageHandler();
	~MessageHandlerIndustry();
private:
	int messageType;
	int messageSize;
	DataStream ds;
};




