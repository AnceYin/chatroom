#include "MessageHandlerCreate.h"

MessageHandler *MessageHandlerIndustry::CreateMessageHandler()
{
	int msgType = this->msgType;
	int msgSize = this->messageSize;
	MessageHandler *handler;

	switch (msgType)
	{
	case LOG_IN:
		handler = new Message_LOG_IN_Handler();
		return handler;
		break;
	case SIGN_IN:
		handler = new Message_SIGN_IN_Handler();
		return handler;
		break;
	case CHANGE_USERNAME:
		handler = new Message_CHANGE_USERNAME_Handler();
		return handler;
		break;
	case CHANGE_PASSWORD:
		handler = new Message_CHANGE_PASSWORD_Handler();
		return handler;
		break;
	case CREAT_TEAM:
		handler = new Message_CREAT_TEAM_Handler();
		return handler;
		break;
	case JOIN_TEAM:
		handler = new Message_JOIN_TEAM_Handler();
		return handler;
		break;
	case SEND_MESSAGE:
		handler = new Message_SEND_MESSAGE_Handler();
		return handler;
		break;
	case CHANGE_TEAM_NAME:
		handler = new Message_CHANGE_TEAM_NAME_Handler();
		return handler;
		break;
	case DELETE_TEAM:
		handler = new Message_DELETE_TEAM_Handler();
		return handler;
		break;
	case QUERY_TEAMS_BY_USER_ID:
		handler = new Message_QUERY_TEAMS_BY_USER_ID_Handler();
		return handler;
		break;
	case QUERY_USERS_BY_TEAM_ID:
		handler = new Message_QUERY_USERS_BY_TEAM_ID_Handler();
		return handler;
		break;
	case QUERY_TEAMS_BY_CREATOR_ID:
		handler = new Message_QUERY_TEAMS_BY_CREATOR_ID_Handler();
		return handler;
		break;
	case QUERY_CREATOR_BY_TEAM_ID:
		handler = new Message_QUERY_CREATOR_BY_TEAM_ID_Handler();
		return handler;
		break;
	case QUERY_USERNAME_BY_USER_ID:
		handler = new Message_QUERY_USERNAME_BY_USER_ID_Handler();
		return handler;
		break;
	case QUERY_USER_IDS_BY_USERNAME:
		handler = new Message_QUERY_USER_IDS_BY_USERNAME_Handler();
		return handler;
		break;
	case QUERY_TEAM_NAME_BY_TEAM_ID:
		handler = new Message_QUERY_TEAM_NAME_BY_TEAM_ID_Handler();
		return handler;
		break;
	case QUERY_TEAM_IDS_BY_TEAM_NAME:
		handler = new Message_QUERY_TEAM_IDS_BY_TEAM_NAME_Handler();
		return handler;
		break;
	case DELETE_ACCOUNT:
		handler = new Message_DELETE_ACCOUNT_Handler();
		return handler;
		break;
	case LEAVE_TEAM:
		handler = new Message_LEAVE_TEAM_Handler();
		return handler;
		break;
	case TRANSFER_CREATOR:
		handler = new Message_TRANSFER_CREATOR_Handler();
		return handler;
		break;
	case QUERY_USER_IN_TEAM:
		handler = new Message_TRANSFER_CREATOR_Handler();
		return handler;
		break;
	}
	return nullptr;
}

MessageHandlerIndustry::~MessageHandlerIndustry()
{
	// 析构函数实现
}