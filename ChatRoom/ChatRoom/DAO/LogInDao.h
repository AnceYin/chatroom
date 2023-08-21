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

// 用户登录函数
bool userLogin(string user_id, string password);

// 用户注册函数
int userRegister(string username, string password);

// 更改用户名函数
void changeUsername(int user_id, string new_username);

// 更改密码函数
bool changePassword(int user_id, string password, string new_password);

// 创建群聊函数
int createTeam(int user_id, string team_name);

// 加入群聊函数
void joinTeam(int user_id, int team_id); 

// 获取要转发的ID列表
vector<int> getForwardingIDs(int user_id, int team_id);

// 更改群名函数
bool changeTeamName(int user_id, int team_id, string new_team_name);

// 删除群聊函数
bool deleteTeam(int user_id, int team_id);
