#ifndef NET_CPP
#define NET_CPP

#include <iostream>
enum MessageType {
	LOG_IN,
	SIGN_IN,
	NAME_CHANGE,
	PWD_CHANGE,
	CREAT_TEAM,
	JOIN_TEAM,
	GET_FORWARDING_IDS,
	CHANGE_TEAM_NAME,
	DELETE_TEAM,
	GET_TEAM_ID,
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





