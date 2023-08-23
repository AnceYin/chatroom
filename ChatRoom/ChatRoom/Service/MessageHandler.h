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
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "../DAO/LogInDao.h"
#include "../net.cpp"

// 01|诺诺|123456->["01", "诺诺", "123456"]
std::vector<std::string> splitString(const std::string &str);

//[1,2,3]->"1|2|3"
std::string packIntVector(const std::vector<int>& intVector);

// true->"1", false->"0"
std::string boolToString(bool b);

class MessageHandler
{
public:
   MessageHandler() {}
   virtual std::string HandleMessage(const std::string &str) = 0;
   virtual std::vector<int> MessageSentList(const std::string &str) = 0;
   ~MessageHandler() {}

private:
};

class Message_LOG_IN_Handler : public MessageHandler
{
public:
   std::string HandleMessage(const std::string &str) override;

   std::vector<int> MessageSentList(const std::string &str) override;
};

class Message_SIGN_IN_Handler : public MessageHandler
{
public:
   std::string HandleMessage(const std::string &str) override;

   std::vector<int> MessageSentList(const std::string &str) override;

private:
   int userID{};
};

class Message_CHANGE_USERNAME_Handler : public MessageHandler
{
public:
   std::string HandleMessage(const std::string &str) override;

   std::vector<int> MessageSentList(const std::string &str) override;
};

class Message_CHANGE_PASSWORD_Handler : public MessageHandler
{
public:
   std::string HandleMessage(const std::string &str) override;

   std::vector<int> MessageSentList(const std::string &str) override;
};

class Message_CREAT_TEAM_Handler : public MessageHandler
{
public:
   std::string HandleMessage(const std::string &str) override;

   std::vector<int> MessageSentList(const std::string &str) override;
};

class Message_JOIN_TEAM_Handler : public MessageHandler
{
public:
   std::string HandleMessage(const std::string &str) override;

   std::vector<int> MessageSentList(const std::string &str) override;
};

class Message_SEND_MESSAGE_Handler : public MessageHandler
{
public:
   std::string HandleMessage(const std::string &str) override;

   std::vector<int> MessageSentList(const std::string &str) override;
};

class Message_CHANGE_TEAM_NAME_Handler : public MessageHandler
{
public:
   std::string HandleMessage(const std::string &str) override;

   std::vector<int> MessageSentList(const std::string &str) override;
};

class Message_DELETE_TEAM_Handler : public MessageHandler
{
public:
   std::string HandleMessage(const std::string &str) override;

   std::vector<int> MessageSentList(const std::string &str) override;
};

class Message_QUERY_TEAMS_BY_USER_ID_Handler : public MessageHandler
{
public:
   std::string HandleMessage(const std::string &str) override;

   std::vector<int> MessageSentList(const std::string &str) override;
};

class Message_QUERY_USERS_BY_TEAM_ID_Handler : public MessageHandler {
public:
   std::string HandleMessage(const std::string& str) override;

   std::vector<int> MessageSentList(const std::string& str) override;
};

class Message_QUERY_TEAMS_BY_CREATOR_ID_Handler : public MessageHandler {
public:
   std::string HandleMessage(const std::string& str) override;

   std::vector<int> MessageSentList(const std::string& str) override;
};

class Message_QUERY_CREATOR_BY_TEAM_ID_Handler : public MessageHandler {
public:
   std::string HandleMessage(const std::string& str) override;

   std::vector<int> MessageSentList(const std::string& str) override;
};

class Message_QUERY_USERNAME_BY_USER_ID_Handler : public MessageHandler {
public:
   std::string HandleMessage(const std::string& str) override;

   std::vector<int> MessageSentList(const std::string& str) override;
};

class Message_QUERY_USER_IDS_BY_USERNAME_Handler : public MessageHandler {
public:
   std::string HandleMessage(const std::string& str) override;

   std::vector<int> MessageSentList(const std::string& str) override;
};

class Message_QUERY_TEAM_NAME_BY_TEAM_ID_Handler : public MessageHandler {
public:
   std::string HandleMessage(const std::string& str) override;

   std::vector<int> MessageSentList(const std::string& str) override;
};

class Message_QUERY_TEAM_IDS_BY_TEAM_NAME_Handler : public MessageHandler {
public:
   std::string HandleMessage(const std::string& str) override;

   std::vector<int> MessageSentList(const std::string& str) override;
};

class Message_DELETE_ACCOUNT_Handler : public MessageHandler {
public:
   std::string HandleMessage(const std::string& str) override;

   std::vector<int> MessageSentList(const std::string& str) override;
};

class Message_LEAVE_TEAM_Handler : public MessageHandler {
public:
   std::string HandleMessage(const std::string& str) override;

   std::vector<int> MessageSentList(const std::string& str) override;
};

class Message_TRANSFER_CREATOR_Handler : public MessageHandler {
public:
   std::string HandleMessage(const std::string& str) override;

   std::vector<int> MessageSentList(const std::string& str) override;
};

class Message_QUERY_USER_IN_TEAM_Handler : public MessageHandler {
public:
   std::string HandleMessage(const std::string& str) override;

   std::vector<int> MessageSentList(const std::string& str) override;
};