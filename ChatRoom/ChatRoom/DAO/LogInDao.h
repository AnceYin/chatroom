#include "../config/mysql_config.h"
#include <mysql_driver.h>
#include <mysql_connection.h>

#include <iostream>
#include <string>

using namespace std;

// 用户信息
struct User {
	int user_id;
	string username;
	string password;
	string status;
};

// 用户登录函数
bool userLogin(string username, string password) {
	sql::mysql::MySQL_Driver* driver;
	sql::Connection* con;

	// 创建MySQL连接
	driver = sql::mysql::get_mysql_driver_instance();
	con = driver->connect(HOST, USERNAME, PASSWORD);

	// 选择数据库
	con->setSchema(DATABASE);

	// 执行登录查询
	sql::Statement* stmt;
	sql::ResultSet* res;

	stmt = con->createStatement();
	res = stmt->executeQuery("SELECT * FROM Users WHERE username = '" + username + "' AND password = '" + password + "'");

	// 检查查询结果
	bool success = res->next();

	// 释放资源
	delete res;
	delete stmt;
	delete con;
	return success;
}

// 用户注册函数
bool userRegister(string username, string password) {
	sql::mysql::MySQL_Driver* driver;
	sql::Connection* con;

	// 创建MySQL连接
	driver = sql::mysql::get_mysql_driver_instance();
	con = driver->connect(HOST, USERNAME, PASSWORD);

	// 选择数据库
	con->setSchema(DATABASE);

	// 执行注册查询
	sql::PreparedStatement* pstmt;
	pstmt = con->prepareStatement("INSERT INTO Users (username, password) VALUES (?, ?)");
	pstmt->setString(1, username);
	pstmt->setString(2, password);
	pstmt->execute();

	// 释放资源
	delete pstmt;
	delete con;
	return true;
}

// 更改用户名函数
bool changeUsername(int user_id, string old_password, string new_username) {
	sql::mysql::MySQL_Driver* driver;
	sql::Connection* con;

	// 创建MySQL连接
	driver = sql::mysql::get_mysql_driver_instance();
	con = driver->connect(HOST, USERNAME, PASSWORD);

	// 选择数据库
	con->setSchema(DATABASE);

	// 执行查询以验证密码
	sql::Statement* stmt;
	sql::ResultSet* res;

	stmt = con->createStatement();
	res = stmt->executeQuery("SELECT * FROM Users WHERE user_id = " + to_string(user_id) + " AND password = '" + old_password + "'");

	// 如果密码验证通过，则执行更改用户名操作
	if (res->next()) {
		sql::PreparedStatement* pstmt;
		pstmt = con->prepareStatement("UPDATE Users SET username = ? WHERE user_id = ?");
		pstmt->setString(1, new_username);
		pstmt->setInt(2, user_id);
		pstmt->execute();

		// 释放资源
		delete pstmt;
		delete res;
		delete stmt;
		delete con;
		return true;
	}
	else {
		// 释放资源
		delete res;
		delete stmt;
		delete con;
		return false;
	}
}

// 更改密码函数
bool changePassword(int user_id, string old_password, string new_password) {
	sql::mysql::MySQL_Driver* driver;
	sql::Connection* con;

	// 创建MySQL连接
	driver = sql::mysql::get_mysql_driver_instance();
	con = driver->connect(HOST, USERNAME, PASSWORD);

	// 选择数据库
	con->setSchema(DATABASE);

	// 执行查询以验证密码
	sql::Statement* stmt;
	sql::ResultSet* res;

	stmt = con->createStatement();
	res = stmt->executeQuery("SELECT * FROM Users WHERE user_id = " + to_string(user_id) + " AND password = '" + old_password + "'");

	// 如果密码验证通过，则执行更改密码操作
	if (res->next()) {
		sql::PreparedStatement* pstmt;
		pstmt = con->prepareStatement("UPDATE Users SET password = ? WHERE user_id = ?");
		pstmt->setString(1, new_password);
		pstmt->setInt(2, user_id);
		pstmt->execute();

		// 释放资源
		delete pstmt;
		delete res;
		delete stmt;
		delete con;
		return true;
	}
	else {
		// 释放资源
		delete res;
		delete stmt;
		delete con;
		return false;
	}
}
