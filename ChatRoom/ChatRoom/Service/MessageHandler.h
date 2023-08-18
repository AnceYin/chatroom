#pragma once
#include <iostream>
#include "../net.cpp"
#include "../serialize/DataStream.h"
#include "../serialize/Serializable.h"

using namespace yazi::serialize;

// 收到数据类型，分发给合适的类进行处理
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
		// 处理消息CHAT的逻辑
		// 返回数据流回复消息
		DataStream ds_r;

		return ds_r;
	}

	vector<string> MessageSentList(int msgSize, DataStream& ds) override {
		// 处理消息CHAT逻辑
		// 返回发送名单
		vector<string> vs;

		return vs;
	}
};
