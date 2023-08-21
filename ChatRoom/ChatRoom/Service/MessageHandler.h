#pragma once
#include "../net.cpp"
#include "../serialize/std::string.h"
#include "../serialize/Serializable.h"
#include <iostream>
#include <vector>
#include <string>

using namespace yazi::serialize;



/** 简介：
 * 此头文件定义了所有消息类型的所有操作
 * 对接数据库完成相应处理
 * 返回初步处理的结果
 * 
 * 
 * 具体过程：
 * 将用户发来的数据解析成对应字段
 * 传入数据库进行处理
 * 将数据库返回的值以"消息类型|消息体"的形式返回
 * 
*/
std::vector<std::string> splitString(const std::string &str)
{
	std::vector<std::string> substrings;
	std::string substring;
	for (char c : str)
	{
		if (c == '|')
		{
			substrings.push_back(substring);
			substring.clear();
		}
		else
		{
			substring += c;
		}
	}
	if (!substring.empty())
	{
		substrings.push_back(substring);
	}
	return substrings;
}

std::string boolToString(bool b)
{
	return b ? "1" : "0";
}

class MessageHandler
{
public:
	MessageHandler(){}
	virtual std::string HandleMessage(const std::string &str) = 0;
	virtual std::vector<int> MessageSentList(const std::string &str) = 0;
	~MessageHandler(){}

private:
};

class Message_LOG_IN_Handler : public MessageHandler
{
public:
	std::string HandleMessage(const std::string &str) override
	{
		// 格式：00|10001|...   	//从|...到|分割
		std::vector<std::string> v = splitString(str);
		return "00|" + boolToString(userLogin(std::stoi(v[1]), v[2]));
	}

	std::vector<int> MessageSentList(const std::string &str) override
	{
		std::vector<int> vs;
		return vs;
	}
};

class Message_SIGN_IN_Handler : public MessageHandler
{
public:
	std::string HandleMessage(const std::string &str) override
	{
		// 格式：01|...|...返回ID
		std::vector<std::string> v = splitString(str);
		return std::string("01|") + std::to_string(userRegister(v[1], v[2]));
	}

	std::vector<int> MessageSentList(const std::string &str) override
	{
		std::vector<int> vs;
		return vs;
	}
};

class Message_NAME_CHANGE_Handler : public MessageHandler
{
public:
	std::string HandleMessage(const std::string &str) override
	{
		// 格式：02|...|...
		std::vector<std::string> v = splitString(str);
		return std::string("02|") + boolToString(changeUsername(std::stoi(v[1]), v[2]));
	}

	std::vector<int> MessageSentList(const std::string &str) override
	{
		std::vector<int> vs;
		return vs;
	}
};

class Message_PWD_CHANGE_Handler : public MessageHandler
{
public:
	std::string HandleMessage(const std::string &str) override
	{
		// 格式：03|...|...|...
		std::vector<std::string> v = splitString(str);
		return std::string("03|") + boolToString(changePassword(std::stoi(v[1]), v[2], v[3]));
	}

	std::vector<int> MessageSentList(const std::string &str) override
	{
		std::vector<int> vs;
		return vs;
	}
};

class Message_CREAT_TEAM_Handler : public MessageHandler
{
public:
	std::string HandleMessage(const std::string &str) override
	{
		// 格式：04|...|...
		std::vector<std::string> v = splitString(str);
		return std::string("04|") + std::to_string(createTeam(std::stoi(v[1]), v[2]));
	}

	std::vector<int> MessageSentList(const std::string &str) override
	{
		std::vector<int> vs;
		return vs;
	}
};

class Message_JOIN_TEAM_Handler : public MessageHandler
{
public:
	std::string HandleMessage(const std::string &str) override
	{
		// 格式：05|...|...
		std::vector<std::string> v = splitString(str);
		return std::string("05|") + boolToString(joinTeam(std::stoi(v[1]), std::stoi(v[2])));
	}

	std::vector<int> MessageSentList(const std::string &str) override
	{
		std::vector<int> vs;
		return vs;
	}
};

class Message_GET_FORWARDING_IDS_Handler : public MessageHandler
{
public:
	std::string HandleMessage(const std::string &str) override
	{
		return str;
	}

	std::vector<int> MessageSentList(const std::string &str) override
	{
		// 格式：06|...|...
		std::vector<std::string> v = splitString(str);
		return getForwardingIDs(std::stoi(v[1]), std::stoi(v[2]));
	}
};

class Message_CHANGE_TEAM_NAME_Handler : public MessageHandler
{
public:
	std::string HandleMessage(const std::string &str) override
	{
		// 格式：07|...|...|...
		std::vector<std::string> v = splitString(str);
		return std::string("07|") + boolToString(changeTeamName(std::stoi(v[1]), std::stoi(v[2]), v[3]));
	}

	std::vector<int> MessageSentList(const std::string &str) override
	{
		std::vector<int> vs;
		return vs;
	}
};

class Message_DELETE_TEAM_Handler : public MessageHandler
{
public:
	std::string HandleMessage(const std::string &str) override
	{
		// 格式：08|...|...
		std::vector<std::string> v = splitString(str);
		return std::string("08|") + boolToString(deleteTeam(std::stoi(v[1]), std::stoi(v[2])));
	}

	std::vector<int> MessageSentList(const std::string &str) override
	{
		std::vector<int> vs;
		return vs;
	}
};

/*

int main()
{
  std::string message;

  // 测试登录消息处理
  Message_LOG_IN_Handler logInHandler;
  message = "00|10001|password";
  std::string loginResult = logInHandler.HandleMessage(message);
  std::cout << "登录结果：" << loginResult << std::endl;

  // 测试注册消息处理
  Message_SIGN_IN_Handler signInHandler;
  message = "01|username|password";
  std::string registerResult = signInHandler.HandleMessage(message);
  std::cout << "注册结果：" << registerResult << std::endl;

  // 测试更改用户名消息处理
  Message_NAME_CHANGE_Handler nameChangeHandler;
  message = "02|10001|new_username";
  std::string nameChangeResult = nameChangeHandler.HandleMessage(message);
  std::cout << "更改用户名结果：" << nameChangeResult << std::endl;

  // 测试更改密码消息处理
  Message_PWD_CHANGE_Handler pwdChangeHandler;
  message = "03|10001|old_password|new_password";
  std::string pwdChangeResult = pwdChangeHandler.HandleMessage(message);
  std::cout << "更改密码结果：" << pwdChangeResult << std::endl;

  // 测试创建团队消息处理
  Message_CREAT_TEAM_Handler createTeamHandler;
  message = "04|10001|team_name";
  std::string createTeamResult = createTeamHandler.HandleMessage(message);
  std::cout << "创建团队结果：" << createTeamResult << std::endl;

  // 测试加入团队消息处理
  Message_JOIN_TEAM_Handler joinTeamHandler;
  message = "05|10001|20001";
  std::string joinTeamResult = joinTeamHandler.HandleMessage(message);
  std::cout << "加入团队结果：" << joinTeamResult << std::endl;

  // 测试获取转发消息处理
  Message_GET_FORWARDING_IDS_Handler getForwardingIDsHandler;
  message = "06|10001|20001";
  std::vector<int> forwardingIDs = getForwardingIDsHandler.MessageSentList(message);
  std::cout << "转发消息列表：" << std::endl;
  for (int id : forwardingIDs)
  {
    std::cout << id << std::endl;
  }

  // 测试更改团队名称消息处理
  Message_CHANGE_TEAM_NAME_Handler changeTeamNameHandler;
  message = "07|10001|20001|new_team_name";
  std::string changeTeamNameResult = changeTeamNameHandler.HandleMessage(message);
  std::cout << "更改团队名称结果：" << changeTeamNameResult << std::endl;

  // 测试删除团队消息处理
  Message_DELETE_TEAM_Handler deleteTeamHandler;
  message = "08|10001|20001";
  std::string deleteTeamResult = deleteTeamHandler.HandleMessage(message);
  std::cout << "删除团队结果：" << deleteTeamResult << std::endl;

  return 0;
}


*/