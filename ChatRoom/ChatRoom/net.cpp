#ifndef NET_CPP
#define NET_CPP

#include <iostream>
enum MessageType {
	LOG_IN,
	SIGN_IN,
	NAME_CHANGE,
	PWD_CHANGE,
	GROUP_CHAT,
	FRIEND_CHAT,
	DELETE_FRIEND,
	ADD_FRIEND,
	ADD_GROUP,
	CHAT_FRIEND,
	CREATE_GROUP,
	LOG_IN_RETURN,
	SIGN_IN_RETURN,
	NAME_CHANGE_RETURN,
	PWD_CHANGE_RETURN,
	GROUP_CHAT_RETURN,
	FRIEND_CHAT_RETURN,
	DELETE_FRIEND_RETURN,
	ADD_FRIEND_RETURN,
	ADD_GROUP_RETURN,
	CREATE_GROUP_RETURN,
};
#endif // NET_CPP

// 所有结构体前有一个int msgType msgSize
//struct LOG_IN
//{
//	std::string username;
//	std::string password;
//};
//
//struct LOG_IN_RETURN
//{
//	bool SucessOrNot;
//};
//
//struct SIGN_IN
//{
//	std::string username;
//	std::string password;
//};
//
//struct SIGN_IN_RETURN
//{
//	bool SucessOrNot;
//};
//
//struct CREATE_GROUP
//{
//	std::string ownerName;
//	std::string groupNumber;
//};
//
//struct CREATE_GROUP_RETURN
//{
//	bool SucessOrNot;
//};
//
//struct ADD_GROUP
//{
//	std::string username;
//	std::string groupNumber;
//};
//
//struct ADD_GROUP_RETURN
//{
//	bool SucessOrNot;
//};
//
//struct GROUP_CHAT
//{
//	std::string groupNumber;
//	std::string sperkerName;
//	std::string content;
//};
//
//struct FRIEND_CHAT
//{
//	std::string sperkerName;
//	std::string content;
//};





