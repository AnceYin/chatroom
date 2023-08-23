#ifndef NET_CPP
#define NET_CPP

#include <iostream>
enum MessageType
{
	// 登录?
	// 00|user_id|password
	// 00|0/1
	LOG_IN = 0,

	// 注册
	// 01|username|password
	// 01|user_id
	SIGN_IN = 1,

	// 更改用户名
	// 02|user_id|new_username
	// 02|0/1
	CHANGE_USERNAME = 2,

	// 更改密码?
	// 03|user_id|password|new_password
	// 03|0/1
	CHANGE_PASSWORD = 3,

	// 创建群聊
	// 04|user_id|team_name
	// 04|team_id
	CREAT_TEAM = 4,

	// 加入群聊
	// 05|user_id|team_id
	// 05|0/1
	JOIN_TEAM = 5,

	// 发消息 乱码
	// 06|user_id|team_id|群聊信息
	// 06|user_id|team_id|群聊信息
	SEND_MESSAGE = 6,

	// 更改群名
	// 07|user_id|team_id|new_team_name
	// 07|0/1
	CHANGE_TEAM_NAME = 7,

	// 删除群聊
	// 08|user_id|team_id
	// 08|0/1
	DELETE_TEAM = 8,

	// 查询指定用户ID所在的所有群聊ID 无返回值
	// 09|user_id
	// 09|team_id|team_id...
	QUERY_TEAMS_BY_USER_ID = 9,

	// 查询指定群聊ID所有成员用户ID 无返回值
	// 10|user_id|team_id
	// 10|user_id|user_id...
	QUERY_USERS_BY_TEAM_ID = 10,

	// 查询指定用户ID创建的所有群聊ID 无返回值
	// 11|user_id
	// 11|team_id|team_id...
	QUERY_TEAMS_BY_CREATOR_ID = 11,

	// 查询指定群聊ID创建者ID 返回-1
	// 12|user_id|team_id
	// 12|user_id
	QUERY_CREATOR_BY_TEAM_ID = 12,

	// 查询指定用户ID用户名 无法显示
	// 13|user_id
	// 13|username
	QUERY_USERNAME_BY_USER_ID = 13,

	// 查询指定用户名所有用户ID 返回错误，返回了用户名
	// 14|user_id|username
	// 14|user_id|user_id...
	QUERY_USER_IDS_BY_USERNAME = 14,

	// 查询指定群聊ID群名 返回15|
	// 15|user_id|team_id
	// 15|team_name
	QUERY_TEAM_NAME_BY_TEAM_ID = 15,

	// 查询指定群名所有群聊ID 返回15|
	// 16|user_id|team_name
	// 16|team_id|team_id...
	QUERY_TEAM_IDS_BY_TEAM_NAME = 16,

	// 删除账号 控制台错误，应不需要返回，并没有被删除
	// 17|user_id|password
	// 17|0/1
	DELETE_ACCOUNT = 17,

	// 退出群聊
	// 18|user_id|team_id
	// 18|0/1
	LEAVE_TEAM = 18,

	// 转交创建者身份
	// 19|user_id|to_user_id
	// 19|0/1
	TRANSFER_CREATOR = 19,

	// 查询用户是否在指定群聊
	// 20|user_id|team_id
	// 20|0/1
	QUERY_USER_IN_TEAM = 20

	// 退出登录 未写
};
#endif // NET_CPP