#pragma once
#include <iostream>
#include <vector>
#include "../DAO/LogInDao.h"
#include "../net.cpp"

using namespace std;

// �յ��������ͣ��ַ������ʵ�����д���
class MessageHandler
{
public:
	virtual std::string HandleMessage(int msgSize, std::string str) = 0;
	virtual vector<string> MessageSentList(int msgSize, std::string str) = 0;
private:
};




class Message_LOG_IN_Handler : public MessageHandler {
public:
	std::string HandleMessage(int msgSize, std::string str) override {

			// ������ϢCHAT���߼�
			// �����������ظ���Ϣ
		std::string ds_r = "11|0" ;
		

		return ds_r;
	}

	vector<string> MessageSentList(int msgSize, std::string str) override {
		// ������ϢCHAT�߼�
		// ���ط�������
		vector<string> vs;
		vs.push_back("123654");


		return vs;
	}
};