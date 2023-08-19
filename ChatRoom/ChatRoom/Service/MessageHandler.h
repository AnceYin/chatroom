#pragma once
#include <iostream>
#include "../net.cpp"
#include "../serialize/DataStream.h"
#include "../serialize/Serializable.h"

// �յ��������ͣ��ַ������ʵ�����д���
class MessageHandler
{
public:
	MessageHandler();
	virtual std::string HandleMessage(int msgSize, std::string str) = 0;
	virtual vector<string> MessageSentList(int msgSize, std::string str) = 0;
	~MessageHandler();
private:
};

class Message_LOG_IN_Handler : public MessageHandler {
public:
	std::string HandleMessage(int msgSize, std::string str) override {
		// ������ϢCHAT���߼�
		// �����������ظ���Ϣ
		std::string ds_r;

		return ds_r;
	}

	vector<string> MessageSentList(int msgSize, std::string str) override {
		// ������ϢCHAT�߼�
		// ���ط�������
		vector<string> vs;

		return vs;
	}
};
