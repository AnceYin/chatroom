#pragma once
#include <iostream>
#include "../net.cpp"
#include "../serialize/DataStream.h"
#include "../serialize/Serializable.h"

using namespace yazi::serialize;

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
		DataStream ds_r;

		return ds_r;
	}

	vector<string> MessageSentList(int msgSize, DataStream& ds) override {
		// ������ϢCHAT�߼�
		// ���ط�������
		vector<string> vs;

		return vs;
	}
};
