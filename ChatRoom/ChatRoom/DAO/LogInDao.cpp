#include "LogInDao.h"

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

bool changeUsername(int user_id, string new_username) {
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
        return true;
    }
    catch (SQLException& e) {
        cout << "SQL Exception: " << e.what() << endl;
        return false;
    }
}

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

bool joinTeam(int user_id, int team_id) {
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