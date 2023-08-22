#include "MessageHandlerCreate.h"

MessageHandler* MessageHandlerIndustry::CreateMessageHandler() {
	int msgType = this->msgType;
	int msgSize = this->messageSize;
	MessageHandler* handler;

	switch (msgType)
	{
	case LOG_IN://登录
		handler = new Message_LOG_IN_Handler();
		return handler;
		break;
	case SIGN_IN://注册
		handler = new Message_SIGN_IN_Handler();
		return handler;
		break;
	case NAME_CHANGE://改昵称
		handler = new Message_NAME_CHANGE_Handler();
		return handler;
		break;
	case PWD_CHANGE://改密码
		handler = new Message_PWD_CHANGE_Handler();
		return handler;
		break;
	case CREAT_TEAM://建群
		handler = new Message_CREAT_TEAM_Handler();
		return handler;
		break;
	case JOIN_TEAM://加群
		handler = new Message_JOIN_TEAM_Handler();
		return handler;
		break;
	case GET_FORWARDING_IDS:// 获取转发列表
		handler = new Message_GET_FORWARDING_IDS_Handler();
		return handler;
		break;
	case CHANGE_TEAM_NAME:// 改群名
		handler = new Message_CHANGE_TEAM_NAME_Handler();
		return handler;
		break;
	case DELETE_TEAM: //删除群聊
		handler = new Message_DELETE_TEAM_Handler();
		return handler;
		break;
	case GET_TEAM_ID: // 获取指定用户所在的群聊列表
		handler = new Message_DELETE_TEAM_Handler();
		return handler;
		break;
	}
	return nullptr;
}

MessageHandlerIndustry::~MessageHandlerIndustry() {
	// 析构函数实现
	
}
