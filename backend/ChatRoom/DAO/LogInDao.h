#pragma once
#include "../config/mysql_config.h"
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
using namespace sql;

// 登录
bool logIn(int user_id, string password);

// 注册
int signIn(string username, string password);

// 更改用户名
bool changeUsername(int user_id, string new_username);

// 更改密码
bool changePassword(int user_id, string password, string new_password);

// 创建群聊
int createTeam(int user_id, string team_name);

// 加入群聊
bool joinTeam(int user_id, int team_id); 

// 发消息
vector<int> sendMessage(int user_id, int team_id);

// 更改群名
bool changeTeamName(int user_id, int team_id, string new_team_name);

// 删除群聊
bool deleteTeam(int user_id, int team_id);

// 获取指定user_id加入的所有team_id
vector<int> queryTeamsByUserID(int user_id);

// 查询指定群聊ID所有成员用户ID
vector<int> queryUsersByTeamID(int team_id);

// 查询指定用户ID创建的所有群聊ID
vector<int> queryTeamsByCreatorID(int user_id);

// 查询指定群聊ID创建者ID
int queryCreatorByTeamID(int team_id);

// 查询指定用户ID用户名
string queryUsernameByUserID(int user_id);

// 查询指定用户名所有用户ID
vector<int> queryUserIDsByUsername(string username);

// 查询指定群聊ID群名
string queryTeamNameByTeamID(int team_id);

// 查询指定群名所有群聊ID
vector<int> queryTeamIDsByTeamName(string team_name);

// 删除账号
bool deleteUser(int user_id, string password);

// 退出群聊
bool leaveTeam(int user_id, int team_id);

// 转交创建者身份
bool transferCreator(int user_id, int to_user_id);

// 查询用户是否在指定群聊
bool queryUserInTeam(int user_id, int team_id);