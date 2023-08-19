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
bool userLogin(int user_id, string password) {
    try {
        mysql::MySQL_Driver* driver;
        Connection* con;
        driver = mysql::get_mysql_driver_instance();
        con = driver->connect(HOST, USERNAME, PASSWORD);
        con->setSchema(DATABASE);

        // 执行登录查询
        PreparedStatement* pstmt;
        pstmt = con->prepareStatement("SELECT * FROM Users WHERE user_id = ? AND password = ?");
        pstmt->setInt(1, user_id);
        pstmt->setString(2, password);
        ResultSet* res = pstmt->executeQuery();
        bool success = res->next();

        delete res;
        delete pstmt;
        delete con;
        return success;
    }
    catch (SQLException& e) {
        cout << "SQL Exception: " << e.what() << endl;
        return false;
    }
}

// 用户注册函数
int userRegister(string username, string password) {
    try {
        mysql::MySQL_Driver* driver;
        Connection* con;
        driver = mysql::get_mysql_driver_instance();
        con = driver->connect(HOST, USERNAME, PASSWORD);
        con->setSchema(DATABASE);

        // 执行注册查询
        PreparedStatement* pstmt;
        pstmt = con->prepareStatement("INSERT INTO Users (username, password) VALUES (?, ?)");
        pstmt->setString(1, username);
        pstmt->setString(2, password);
        pstmt->execute();

        // 获取生成的user_id
        Statement* stmt = con->createStatement();
        ResultSet* res = stmt->executeQuery("SELECT LAST_INSERT_ID()");
        res->next();
        int user_id = res->getInt(1);

        delete res;
        delete stmt;
        delete pstmt;
        delete con;
        return user_id;
    }
    catch (SQLException& e) {
        cout << "SQL Exception: " << e.what() << endl;
        return -1;
    }
}

// 更改用户名函数
void changeUsername(int user_id, string new_username) {
    try {
        mysql::MySQL_Driver* driver;
        Connection* con;
        driver = mysql::get_mysql_driver_instance();
        con = driver->connect(HOST, USERNAME, PASSWORD);
        con->setSchema(DATABASE);

        // 执行更改用户名操作
        PreparedStatement* pstmt;
        pstmt = con->prepareStatement("UPDATE Users SET username = ? WHERE user_id = ?");
        pstmt->setString(1, new_username);
        pstmt->setInt(2, user_id);
        pstmt->execute();

        delete pstmt;
        delete con;
    }
    catch (SQLException& e) {
        cout << "SQL Exception: " << e.what() << endl;
    }
}

// 更改密码函数
bool changePassword(int user_id, string password, string new_password) {
    try {
        mysql::MySQL_Driver* driver;
        Connection* con;
        driver = mysql::get_mysql_driver_instance();
        con = driver->connect(HOST, USERNAME, PASSWORD);
        con->setSchema(DATABASE);

        // 验证密码
        PreparedStatement* pstmt;
        pstmt = con->prepareStatement("SELECT * FROM Users WHERE user_id = ? AND password = ?");
        pstmt->setInt(1, user_id);
        pstmt->setString(2, password);
        ResultSet* res = pstmt->executeQuery();
        bool success = res->next();

        if (success) {
            // 更新密码
            pstmt = con->prepareStatement("UPDATE Users SET password = ? WHERE user_id = ?");
            pstmt->setString(1, new_password);
            pstmt->setInt(2, user_id);
            pstmt->execute();
        }

        delete res;
        delete pstmt;
        delete con;
        return success;
    }
    catch (SQLException& e) {
        cout << "SQL Exception: " << e.what() << endl;
        return false;
    }
}

// 创建群聊函数
int createTeam(int user_id, string team_name) {
    try {
        mysql::MySQL_Driver* driver;
        Connection* con;
        driver = mysql::get_mysql_driver_instance();
        con = driver->connect(HOST, USERNAME, PASSWORD);
        con->setSchema(DATABASE);

        // 创建群聊
        PreparedStatement* pstmt;
        pstmt = con->prepareStatement("INSERT INTO Teams (team_name, creator_id) VALUES (?, ?)");
        pstmt->setString(1, team_name);
        pstmt->setInt(2, user_id);
        pstmt->execute();

        // 获取生成的team_id
        Statement* stmt = con->createStatement();
        ResultSet* res = stmt->executeQuery("SELECT LAST_INSERT_ID()");
        res->next();
        int team_id = res->getInt(1);
        // 将创建者加入TeamMember表
        pstmt = con->prepareStatement("INSERT INTO TeamMember (group_id, member_id) VALUES (?, ?)");
        pstmt->setInt(1, team_id);
        pstmt->setInt(2, user_id);
        pstmt->execute();

        delete res;
        delete stmt;
        delete pstmt;
        delete con;
        return team_id;
    }
    catch (SQLException& e) {
        cout << "SQL Exception: " << e.what() << endl;
        return -1;
    }
}

// 加入群聊函数
void joinTeam(int user_id, int team_id) {
    try {
        mysql::MySQL_Driver* driver;
        Connection* con;
        driver = mysql::get_mysql_driver_instance();
        con = driver->connect(HOST, USERNAME, PASSWORD);
        con->setSchema(DATABASE);

        // 加入群聊
        PreparedStatement* pstmt;
        pstmt = con->prepareStatement("INSERT INTO TeamMember (group_id, member_id) VALUES (?, ?)");
        pstmt->setInt(1, team_id);
        pstmt->setInt(2, user_id);
        pstmt->execute();

        delete pstmt;
        delete con;
    }
    catch (SQLException& e) {
        cout << "SQL Exception: " << e.what() << endl;
    }
}

// 获取要转发的ID列表
vector<int> getForwardingIDs(int user_id, int team_id) {
    vector<int> forwardingIDs;
    try {
        mysql::MySQL_Driver* driver;
        Connection* con;
        driver = mysql::get_mysql_driver_instance();
        con = driver->connect(HOST, USERNAME, PASSWORD);
        con->setSchema(DATABASE);

        // 查询群聊中其他用户的id
        PreparedStatement* pstmt;
        pstmt = con->prepareStatement("SELECT member_id FROM TeamMember WHERE group_id = ? AND member_id != ?");
        pstmt->setInt(1, team_id);
        pstmt->setInt(2, user_id);
        ResultSet* res = pstmt->executeQuery();

        // 将要转发的ID添加到转发列表中
        while (res->next()) {
            int member_id = res->getInt("member_id");
            forwardingIDs.push_back(member_id);
        }

        delete res;
        delete pstmt;
        delete con;
    }
    catch (SQLException& e) {
        cout << "SQL Exception: " << e.what() << endl;
    }

    // 返回转发列表
    return forwardingIDs;
}


// 更改群名函数
bool changeTeamName(int user_id, int team_id, string new_team_name) {
    try {
        mysql::MySQL_Driver* driver;
        Connection* con;
        driver = mysql::get_mysql_driver_instance();
        con = driver->connect(HOST, USERNAME, PASSWORD);
        con->setSchema(DATABASE);

        // 根据team_id判断是否为user_id
        PreparedStatement* pstmt;
        pstmt = con->prepareStatement("SELECT * FROM Teams WHERE team_id = ? AND creator_id = ?");
        pstmt->setInt(1, team_id);
        pstmt->setInt(2, user_id);
        ResultSet* res = pstmt->executeQuery();
        bool success = res->next();

        if (success) {
            // 更改群名
            pstmt = con->prepareStatement("UPDATE Teams SET team_name = ? WHERE team_id = ?");
            pstmt->setString(1, new_team_name);
            pstmt->setInt(2, team_id);
            pstmt->execute();
        }

        delete res;
        delete pstmt;
        delete con;
        return success;
    }
    catch (SQLException& e) {
        cout << "SQL Exception: " << e.what() << endl;
        return false;
    }
}

// 删除群聊函数
bool deleteTeam(int user_id, int team_id) {
    try {
        mysql::MySQL_Driver* driver;
        Connection* con;
        driver = mysql::get_mysql_driver_instance();
        con = driver->connect(HOST, USERNAME, PASSWORD);
        con->setSchema(DATABASE);

        // 根据team_id判断是否为user_id
        PreparedStatement* pstmt;
        pstmt = con->prepareStatement("SELECT * FROM Teams WHERE team_id = ? AND creator_id = ?");
        pstmt->setInt(1, team_id);
        pstmt->setInt(2, user_id);
        ResultSet* res = pstmt->executeQuery();
        bool success = res->next();

        if (success) {
            // 清理TeamMember表中相关内容
            pstmt = con->prepareStatement("DELETE FROM TeamMember WHERE group_id = ?");
            pstmt->setInt(1, team_id);
            pstmt->execute();

            // 清理Teams表中相关内容
            pstmt = con->prepareStatement("DELETE FROM Teams WHERE team_id = ?");
            pstmt->setInt(1, team_id);
            pstmt->execute();
        }

        delete res;
        delete pstmt;
        delete con;
        return success;
    }
    catch (SQLException& e) {
        cout << "SQL Exception: " << e.what() << endl;
        return false;
    }
}

/* ------------------------------- test -------------------------------
void testLogin(){
    bool b = userLogin(10001,"password1");
    if(b){
        cout<<"登录成功\n";
    }else {
        cout<<"登录失败\n";
    }
}

void testRegister(){
    string userName {"诺诺"};
    string passWord {"nuo"};
    int id = userRegister(userName, passWord);
    cout<< userName + ", 欢迎您! 您的ID为" << id << "\n";
}

void testChangeUsername(){
    changeUsername(10001,"诺诺");
}

void testChangePassword(){
    bool b1 = changePassword(10001, "password1", "password");
    bool b2 = changePassword(10001, "password1", "password");
    for (auto &&x : {b1, b1}){
        if(x){
            cout<<"修改成功\n";
        }else {
            cout<<"修改失败\n";
        }
    }
}

void testCreateTeam(){
    int i = createTeam(10001,"电池");
    cout<< "创建成功! 群号为: "<< i << "\n";
}

void testJoinTeam(){
    joinTeam(10001, 10000002);
    cout << "请查看数据库, 判断是否添加成功\n";
}

void testGetForwardingIDs(){
    vector<int> v = getForwardingIDs(10001,10000002);
    for (auto &&x : v){
        cout << x << "|";
    }
    cout << endl;
}

void testChangeTeamName(){
    bool b = changeTeamName(10001, 10000001, "电池");
    if(b){
        cout<<"修改成功\n";
    }else {
        cout<<"修改失败\n";
    }
}

void testDeleteTeam(){
    bool b = deleteTeam(10001, 10000001);
    if(b){
        cout<<"删除成功\n";
    }else {
        cout<<"删除失败\n";
    }
}

int main(){
    testDeleteTeam();
}
----------------------------------------------------*/
