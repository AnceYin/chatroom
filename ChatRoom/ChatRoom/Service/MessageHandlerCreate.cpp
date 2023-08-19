#include "MessageHandlerCreate.h"

MessageHandler* MessageHandlerIndustry::CreateMessageHandler() {
	std::string msgType = this->messageType;
	int msgSize = this->messageSize;

	switch (msgType)
	{
	case "01":
		MessageHandler* handler = new Message_LOG_IN_Handler();
		return handler;
		break;
	case "02":
		MessageHandler* handler = new Message_LOG_IN_Handler();
		return handler;
		break;
	case "03":
		MessageHandler* handler = new Message_LOG_IN_Handler();
		return handler;
		break;
	case "04":
		MessageHandler* handler = new Message_LOG_IN_Handler();
		return handler;
		break;
	case "05":
		MessageHandler* handler = new Message_LOG_IN_Handler();
		return handler;
		break;
	case "06":
		MessageHandler* handler = new Message_LOG_IN_Handler();
		return handler;
		break;
	case "07":
		MessageHandler* handler = new Message_LOG_IN_Handler();
		return handler;
		break;
	case "08":
		MessageHandler* handler = new Message_LOG_IN_Handler();
		return handler;
		break;
	case "09":
		MessageHandler* handler = new Message_LOG_IN_Handler();
		return handler;
		break;
	case "10":
		MessageHandler* handler = new Message_LOG_IN_Handler();
		return handler;
		break;
	}
}
