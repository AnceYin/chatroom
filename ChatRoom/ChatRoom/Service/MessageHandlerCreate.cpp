#include "MessageHandlerCreate.h"

MessageHandler* MessageHandlerIndustry::CreateMessageHandler() {
	int msgType = this->messageType;
	int msgSize = this->messageSize;

	switch (msgType)
	{
	case LOG_IN:
		MessageHandler* handler = new Message_LOG_IN_Handler();
		return handler;
		break;
	case SIGN_IN:
		MessageHandler* handler = new Message_LOG_IN_Handler();
		return handler;
		break;
	case NAME_CHANGE:
		MessageHandler* handler = new Message_LOG_IN_Handler();
		return handler;
		break;
	case PWD_CHANGE:
		MessageHandler* handler = new Message_LOG_IN_Handler();
		return handler;
		break;
	case GROUP_CHAT:
		MessageHandler* handler = new Message_LOG_IN_Handler();
		return handler;
		break;
	case FRIEND_CHAT:
		MessageHandler* handler = new Message_LOG_IN_Handler();
		return handler;
		break;
	case DELETE_FRIEND:
		MessageHandler* handler = new Message_LOG_IN_Handler();
		return handler;
		break;
	case ADD_FRIEND:
		MessageHandler* handler = new Message_LOG_IN_Handler();
		return handler;
		break;
	case ADD_GROUP:
		MessageHandler* handler = new Message_LOG_IN_Handler();
		return handler;
		break;
	case CREATE_GROUP:
		MessageHandler* handler = new Message_LOG_IN_Handler();
		return handler;
		break;
	}
}
