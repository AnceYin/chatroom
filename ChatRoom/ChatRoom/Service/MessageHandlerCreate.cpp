#include "MessageHandlerCreate.h"

MessageHandler* MessageHandlerIndustry::CreateMessageHandler() {
	int msgType = this->msgType;
	int msgSize = this->messageSize;

	switch (msgType)
	{
	case 0:
		MessageHandler * handler = new Message_LOG_IN_Handler();
		return handler;
		break;
	//case 1:
	//	MessageHandler * handler = new Message_LOG_IN_Handler();
	//	return handler;
	//	break;
	/*case 2:
		MessageHandler * handler = new Message_LOG_IN_Handler();
		return handler;
		break;
	case 3:
		MessageHandler * handler = new Message_LOG_IN_Handler();
		return handler;
		break;
	case 4:
		MessageHandler * handler = new Message_LOG_IN_Handler();
		return handler;
		break;
	case 5:
		MessageHandler * handler = new Message_LOG_IN_Handler();
		return handler;
		break;
	case 6:
		MessageHandler * handler = new Message_LOG_IN_Handler();
		return handler;
		break;
	case 7:
		MessageHandler * handler = new Message_LOG_IN_Handler();
		return handler;
		break;
	case 8:
		MessageHandler * handler = new Message_LOG_IN_Handler();
		return handler;
		break;
	case 9:
		MessageHandler * handler = new Message_LOG_IN_Handler();
		return handler;
		break;
	case 10:
		MessageHandler * handler = new Message_LOG_IN_Handler();
		return handler;
		break;*/
	}
	return nullptr;
}

MessageHandlerIndustry::~MessageHandlerIndustry() {
	// 析构函数实现
}