#include "MessageHandler.h"

std::vector<std::string> splitString(const std::string& str)
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

std::string boolToString(bool b) {
	return b ? "1" : "0";
}


std::string Message_LOG_IN_Handler::HandleMessage(const std::string& str)
	{
		// 格式：00|10001|...   	//从|...到|分割
		std::vector<std::string> v = splitString(str);
		
		return "00|" + boolToString(userLogin(std::stoi(v[1]), v[2]));
	}

std::vector<int> Message_LOG_IN_Handler::MessageSentList(const std::string& str)
{
	std::vector<std::string> v = splitString(str);
	std::vector<int> vs;
	vs.push_back(std::stoi(v[1]));
	return vs;
}


std::string Message_SIGN_IN_Handler::HandleMessage(const std::string& str)
{
	// 格式：01|...|...返回ID
	std::vector<std::string> v = splitString(str);
	return std::string("01|") + std::to_string(userRegister(v[1], v[2]));
}

std::vector<int> Message_SIGN_IN_Handler::MessageSentList(const std::string& str)
{
	std::vector<int> vs;
	std::vector<std::string> v = splitString(str);
	int res = userRegister(v[1], v[2]);
	vs.push_back(res);

	return vs;
}


std::string Message_NAME_CHANGE_Handler::HandleMessage(const std::string& str) {
	// 格式：02|...|...
	std::vector<std::string> v = splitString(str);
	return std::string("02|") + boolToString(changeUsername(std::stoi(v[1]), v[2]));
}

std::vector<int> Message_NAME_CHANGE_Handler::MessageSentList(const std::string& str) {
	std::vector<int> vs;
	return vs;
}


std::string Message_PWD_CHANGE_Handler::HandleMessage(const std::string& str) {
	// 格式：03|...|...|...
	std::vector<std::string> v = splitString(str);
	return std::string("03|") + boolToString(changePassword(std::stoi(v[1]), v[2], v[3]));
}

std::vector<int> Message_PWD_CHANGE_Handler::MessageSentList(const std::string& str) {
	std::vector<int> vs;
	return vs;
}


std::string Message_CREAT_TEAM_Handler::HandleMessage(const std::string& str) {
	// 格式：04|...|...
	std::vector<std::string> v = splitString(str);
	return std::string("04|") + std::to_string(createTeam(std::stoi(v[1]), v[2]));
}

std::vector<int> Message_CREAT_TEAM_Handler::MessageSentList(const std::string& str) {
	std::vector<int> vs;
	std::vector<std::string> v = splitString(str);
	vs.push_back(std::stoi(v[1]));
	return vs;
}


std::string Message_JOIN_TEAM_Handler::HandleMessage(const std::string& str) {
	// 格式：05|...|...
	std::vector<std::string> v = splitString(str);
	return std::string("05|") + boolToString(joinTeam(std::stoi(v[1]), std::stoi(v[2])));
}

std::vector<int> Message_JOIN_TEAM_Handler::MessageSentList(const std::string& str) {
	std::vector<int> vs;
	return vs;
}


std::string Message_GET_FORWARDING_IDS_Handler::HandleMessage(const std::string& str) {
	return str;
}

std::vector<int> Message_GET_FORWARDING_IDS_Handler::MessageSentList(const std::string& str) {
	// 格式：06|...|...
	std::vector<std::string> v = splitString(str);
	return getForwardingIDs(std::stoi(v[1]), std::stoi(v[2]));
}


std::string Message_CHANGE_TEAM_NAME_Handler::HandleMessage(const std::string& str) {
	// 格式：07|...|...|...
	std::vector<std::string> v = splitString(str);
	return std::string("07|") + boolToString(changeTeamName(std::stoi(v[1]), std::stoi(v[2]), v[3]));
}

std::vector<int> Message_CHANGE_TEAM_NAME_Handler::MessageSentList(const std::string& str) {
	std::vector<int> vs;
	return vs;
}


std::string Message_DELETE_TEAM_Handler::HandleMessage(const std::string& str) {
	// 格式：08|...|...
	std::vector<std::string> v = splitString(str);
	return std::string("08|") + boolToString(deleteTeam(std::stoi(v[1]), std::stoi(v[2])));
}

std::vector<int> Message_DELETE_TEAM_Handler::MessageSentList(const std::string& str) {
	std::vector<int> vs;
	return vs;
}