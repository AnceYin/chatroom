#include "MessageHandler.h"

// 01|诺诺|123456->["01", "诺诺", "123456"]
std::vector<std::string> splitString(const std::string &str)
{
  std::vector<std::string> substrings;
  std::string substring;
  // 累积字符串
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
  // 加入最后一个字符串
  if (!substring.empty())
  {
    substrings.push_back(substring);
  }
  return substrings;
}

//[1,2,3]->"1|2|3"
std::string packIntVector(const std::vector<int> &intVector)
{
  std::string packedString;
  //[1,2,3]->"1|2|3|"
  for (int num : intVector)
  {
    packedString += std::to_string(num) + '|';
  }
  // 移除最后一个 '|' 字符
  if (!packedString.empty())
  {
    packedString.pop_back();
  }
  return packedString;
}

// true->"1", false->"0"
std::string boolToString(bool b)
{
  return b ? "1" : "0";
}

std::string Message_LOG_IN_Handler::HandleMessage(const std::string &str)
{
  std::vector<std::string> v = splitString(str);
  return "00|" + boolToString(logIn(std::stoi(v[1]), v[2]));
}

std::vector<int> Message_LOG_IN_Handler::MessageSentList(const std::string &str)
{
  std::vector<std::string> v = splitString(str);
  std::vector<int> vs;
  vs.push_back(std::stoi(v[1]));
  return vs;
}

std::string Message_SIGN_IN_Handler::HandleMessage(const std::string &str)
{
  std::vector<std::string> v = splitString(str);
  userID = signIn(v[1], v[2]);
  return std::string("01|") + std::to_string(userID);
}

std::vector<int> Message_SIGN_IN_Handler::MessageSentList(const std::string &str)
{
  std::vector<std::string> v = splitString(str);
  std::vector<int> vs;
  vs.push_back(userID);
  return vs;
}

std::string Message_CHANGE_USERNAME_Handler::HandleMessage(const std::string &str)
{
  std::vector<std::string> v = splitString(str);
  return std::string("02|") + boolToString(changeUsername(std::stoi(v[1]), v[2]));
}

std::vector<int> Message_CHANGE_USERNAME_Handler::MessageSentList(const std::string &str)
{
  std::vector<std::string> v = splitString(str);
  std::vector<int> vs;
  vs.push_back(std::stoi(v[1]));
  return vs;
}

std::string Message_CHANGE_PASSWORD_Handler::HandleMessage(const std::string &str)
{
  std::vector<std::string> v = splitString(str);
  return std::string("03|") + boolToString(changePassword(std::stoi(v[1]), v[2], v[3]));
}

std::vector<int> Message_CHANGE_PASSWORD_Handler::MessageSentList(const std::string &str)
{
  std::vector<std::string> v = splitString(str);
  std::vector<int> vs;
  vs.push_back(std::stoi(v[1]));
  return vs;
}

std::string Message_CREAT_TEAM_Handler::HandleMessage(const std::string &str)
{
  std::vector<std::string> v = splitString(str);
  return std::string("04|") + std::to_string(createTeam(std::stoi(v[1]), v[2]));
}

std::vector<int> Message_CREAT_TEAM_Handler::MessageSentList(const std::string &str)
{
  std::vector<std::string> v = splitString(str);
  std::vector<int> vs;
  vs.push_back(std::stoi(v[1]));
  return vs;
}

std::string Message_JOIN_TEAM_Handler::HandleMessage(const std::string &str)
{
  std::vector<std::string> v = splitString(str);
  return std::string("05|") + boolToString(joinTeam(std::stoi(v[1]), std::stoi(v[2])));
}

std::vector<int> Message_JOIN_TEAM_Handler::MessageSentList(const std::string &str)
{
  std::vector<std::string> v = splitString(str);
  std::vector<int> vs;
  vs.push_back(std::stoi(v[1]));
  return vs;
}

std::string Message_SEND_MESSAGE_Handler::HandleMessage(const std::string &str)
{
  return std::string("06") + str;
}

std::vector<int> Message_SEND_MESSAGE_Handler::MessageSentList(const std::string &str)
{
  std::vector<std::string> v = splitString(str);
  return sendMessage(std::stoi(v[1]), std::stoi(v[2]));
}

std::string Message_CHANGE_TEAM_NAME_Handler::HandleMessage(const std::string &str)
{
  std::vector<std::string> v = splitString(str);
  return std::string("07|") + boolToString(changeTeamName(std::stoi(v[1]), std::stoi(v[2]), v[3]));
}

std::vector<int> Message_CHANGE_TEAM_NAME_Handler::MessageSentList(const std::string &str)
{
  std::vector<std::string> v = splitString(str);
  std::vector<int> vs;
  vs.push_back(std::stoi(v[1]));
  return vs;
}

std::string Message_DELETE_TEAM_Handler::HandleMessage(const std::string &str)
{
  std::vector<std::string> v = splitString(str);
  return std::string("08|") + boolToString(deleteTeam(std::stoi(v[1]), std::stoi(v[2])));
}

std::vector<int> Message_DELETE_TEAM_Handler::MessageSentList(const std::string &str)
{
  std::vector<std::string> v = splitString(str);
  std::vector<int> vs;
  vs.push_back(std::stoi(v[1]));
  return vs;
}

std::string Message_QUERY_TEAMS_BY_USER_ID_Handler::HandleMessage(const std::string &str)
{
  std::vector<std::string> v = splitString(str);
  return std::string("09|") + packIntVector(queryTeamsByUserID(std::stoi(v[1])));
}

std::vector<int> Message_QUERY_TEAMS_BY_USER_ID_Handler::MessageSentList(const std::string &str)
{
  std::vector<std::string> v = splitString(str);
  std::vector<int> vs;
  vs.push_back(std::stoi(v[1]));
  return vs;
}

std::string Message_QUERY_USERS_BY_TEAM_ID_Handler::HandleMessage(const std::string &str)
{
  std::vector<std::string> v = splitString(str);
  return std::string("10|") + packIntVector(queryUsersByTeamID(std::stoi(v[1])));
}

std::vector<int> Message_QUERY_USERS_BY_TEAM_ID_Handler::MessageSentList(const std::string &str)
{
  std::vector<std::string> v = splitString(str);
  std::vector<int> vs;
  vs.push_back(std::stoi(v[1]));
  return vs;
}

std::string Message_QUERY_TEAMS_BY_CREATOR_ID_Handler::HandleMessage(const std::string &str)
{
  std::vector<std::string> v = splitString(str);
  return std::string("11|") + packIntVector(queryTeamsByCreatorID(std::stoi(v[1])));
}

std::vector<int> Message_QUERY_TEAMS_BY_CREATOR_ID_Handler::MessageSentList(const std::string &str)
{
  std::vector<std::string> v = splitString(str);
  std::vector<int> vs;
  vs.push_back(std::stoi(v[1]));
  return vs;
}

std::string Message_QUERY_CREATOR_BY_TEAM_ID_Handler::HandleMessage(const std::string &str)
{
  std::vector<std::string> v = splitString(str);
  return std::string("12|") + std::to_string(queryCreatorByTeamID(std::stoi(v[1])));
}

std::vector<int> Message_QUERY_CREATOR_BY_TEAM_ID_Handler::MessageSentList(const std::string &str)
{
  std::vector<std::string> v = splitString(str);
  std::vector<int> vs;
  vs.push_back(std::stoi(v[1]));
  return vs;
}

std::string Message_QUERY_USERNAME_BY_USER_ID_Handler::HandleMessage(const std::string &str)
{
  std::vector<std::string> v = splitString(str);
  return std::string("13|") + queryUsernameByUserID(std::stoi(v[1]));
}

std::vector<int> Message_QUERY_USERNAME_BY_USER_ID_Handler::MessageSentList(const std::string &str)
{
  std::vector<std::string> v = splitString(str);
  std::vector<int> vs;
  vs.push_back(std::stoi(v[1]));
  return vs;
}

std::string Message_QUERY_USER_IDS_BY_USERNAME_Handler::HandleMessage(const std::string &str)
{
  std::vector<std::string> v = splitString(str);
  return std::string("14|") + packIntVector(queryUserIDsByUsername(v[1]));
}

std::vector<int> Message_QUERY_USER_IDS_BY_USERNAME_Handler::MessageSentList(const std::string &str)
{
  std::vector<std::string> v = splitString(str);
  std::vector<int> vs;
  vs.push_back(std::stoi(v[1]));
  return vs;
}

std::string Message_QUERY_TEAM_NAME_BY_TEAM_ID_Handler::HandleMessage(const std::string &str)
{
  std::vector<std::string> v = splitString(str);
  return std::string("15|") + queryTeamNameByTeamID(std::stoi(v[1]));
}

std::vector<int> Message_QUERY_TEAM_NAME_BY_TEAM_ID_Handler::MessageSentList(const std::string &str)
{
  std::vector<std::string> v = splitString(str);
  std::vector<int> vs;
  vs.push_back(std::stoi(v[1]));
  return vs;
}

std::string Message_QUERY_TEAM_IDS_BY_TEAM_NAME_Handler::HandleMessage(const std::string &str)
{
  std::vector<std::string> v = splitString(str);
  return std::string("16|") + packIntVector(queryTeamIDsByTeamName(v[1]));
}

std::vector<int> Message_QUERY_TEAM_IDS_BY_TEAM_NAME_Handler::MessageSentList(const std::string &str)
{
  std::vector<std::string> v = splitString(str);
  std::vector<int> vs;
  vs.push_back(std::stoi(v[1]));
  return vs;
}

std::string Message_DELETE_ACCOUNT_Handler::HandleMessage(const std::string &str)
{
  std::vector<std::string> v = splitString(str);
  return std::string("17|") + boolToString(deleteUser(std::stoi(v[1]), v[2]));
}

std::vector<int> Message_DELETE_ACCOUNT_Handler::MessageSentList(const std::string &str)
{
  std::vector<std::string> v = splitString(str);
  std::vector<int> vs;
  vs.push_back(std::stoi(v[1]));
  return vs;
}

std::string Message_LEAVE_TEAM_Handler::HandleMessage(const std::string &str)
{
  std::vector<std::string> v = splitString(str);
  return std::string("18|") + boolToString(leaveTeam(std::stoi(v[1]), std::stoi(v[2])));
}

std::vector<int> Message_LEAVE_TEAM_Handler::MessageSentList(const std::string &str)
{
  std::vector<std::string> v = splitString(str);
  std::vector<int> vs;
  vs.push_back(std::stoi(v[1]));
  return vs;
}

std::string Message_TRANSFER_CREATOR_Handler::HandleMessage(const std::string &str)
{
  std::vector<std::string> v = splitString(str);
  return std::string("19|") + boolToString(transferCreator(std::stoi(v[1]), std::stoi(v[2])));
}

std::vector<int> Message_TRANSFER_CREATOR_Handler::MessageSentList(const std::string &str)
{
  std::vector<std::string> v = splitString(str);
  std::vector<int> vs;
  vs.push_back(std::stoi(v[1]));
  return vs;
}

std::string Message_QUERY_USER_IN_TEAM_Handler::HandleMessage(const std::string &str)
{
  std::vector<std::string> v = splitString(str);
  return std::string("20|") + boolToString(queryUserInTeam(std::stoi(v[1]), std::stoi(v[2])));
}

std::vector<int> Message_QUERY_USER_IN_TEAM_Handler::MessageSentList(const std::string &str)
{
  std::vector<std::string> v = splitString(str);
  std::vector<int> vs;
  vs.push_back(std::stoi(v[1]));
  return vs;
}

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
  Message_CHANGE_USERNAME_Handler nameChangeHandler;
  message = "02|10001|new_username";
  std::string nameChangeResult = nameChangeHandler.HandleMessage(message);
  std::cout << "更改用户名结果：" << nameChangeResult << std::endl;

  // 测试更改密码消息处理
  Message_CHANGE_PASSWORD_Handler pwdChangeHandler;
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
  Message_SEND_MESSAGE_Handler sendMessageHandler;
  message = "06|10001|20001";
  std::vector<int> forwardingIDs = sendMessageHandler.MessageSentList(message);
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