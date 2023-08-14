#pragma once
#include <iostream>
#include "../net.cpp"
#include "../serialize/DataStream.h"
#include "../serialize/Serializable.h"

using namespace yazi::serialize;

// �������ݴ����๤����
class MessageHandlerIndustry
{
public:
	MessageHandlerIndustry(int msgType, int msgSize, DataStream ds) : messageType(msgType), messageSize(msgSize), ds(ds) {};
	MessageHandler* CreateHandleMessage();
	~MessageHandlerIndustry();
private:
	int messageType;
	int messageSize;
	DataStream ds;
};


// �յ��������ͣ��ַ������ʵ�����д���
class MessageHandler
{
public:
	MessageHandler();
	virtual DataStream HandleMessage(int msgSize, DataStream& ds) = 0;
	virtual vector<string> MessageSentList(int msgSize, DataStream& ds) = 0;
	~MessageHandler();
private:
};

class Message_LOG_IN_Handler : public MessageHandler {
public:
	DataStream HandleMessage(int msgSize, DataStream& ds) override {
		// ������ϢCHAT���߼�
		// �����������ظ���Ϣ
	}

	vector<string> MessageSentList(int msgSize, DataStream& ds) override {
		// ������ϢCHAT�߼�
		// ���ط�������

	}
};


