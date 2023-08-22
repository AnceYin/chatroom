#include "LogInDao.h"

bool userLogin(int user_id, string password) {
    try {
        mysql::MySQL_Driver* driver;
        Connection* con;
        driver = mysql::get_mysql_driver_instance();
        con = driver->connect(HOST, USERNAME, PASSWORD);
        con->setSchema(DATABASE);

        // ִ�е�¼��ѯ
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

        // ִ��ע���ѯ
        PreparedStatement* pstmt;
        pstmt = con->prepareStatement("INSERT INTO Users (username, password) VALUES (?, ?)");
        pstmt->setString(1, username);
        pstmt->setString(2, password);
        pstmt->execute();

        // ��ȡ���ɵ�user_id
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

        // ִ�и����û�������
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

        // ��֤����
        PreparedStatement* pstmt;
        pstmt = con->prepareStatement("SELECT * FROM Users WHERE user_id = ? AND password = ?");
        pstmt->setInt(1, user_id);
        pstmt->setString(2, password);
        ResultSet* res = pstmt->executeQuery();
        bool success = res->next();

        if (success) {
            // ��������
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

        // ����Ⱥ��
        PreparedStatement* pstmt;
        pstmt = con->prepareStatement("INSERT INTO Teams (team_name, creator_id) VALUES (?, ?)");
        pstmt->setString(1, team_name);
        pstmt->setInt(2, user_id);
        pstmt->execute();

        // ��ȡ���ɵ�team_id
        Statement* stmt = con->createStatement();
        ResultSet* res = stmt->executeQuery("SELECT LAST_INSERT_ID()");
        res->next();
        int team_id = res->getInt(1);
        // �������߼���TeamMember��
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

        // ����Ⱥ��
        PreparedStatement* pstmt;
        pstmt = con->prepareStatement("INSERT INTO TeamMember (group_id, member_id) VALUES (?, ?)");
        pstmt->setInt(1, team_id);
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

vector<int> getForwardingIDs(int user_id, int team_id) {
    vector<int> forwardingIDs;
    try {
        mysql::MySQL_Driver* driver;
        Connection* con;
        driver = mysql::get_mysql_driver_instance();
        con = driver->connect(HOST, USERNAME, PASSWORD);
        con->setSchema(DATABASE);

        // ��ѯȺ���������û���id
        PreparedStatement* pstmt;
        pstmt = con->prepareStatement("SELECT member_id FROM TeamMember WHERE group_id = ? AND member_id != ?");
        pstmt->setInt(1, team_id);
        pstmt->setInt(2, user_id);
        ResultSet* res = pstmt->executeQuery();

        // ��Ҫת����ID���ӵ�ת���б���
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

    // ����ת���б�
    return forwardingIDs;
}

bool changeTeamName(int user_id, int team_id, string new_team_name) {
    try {
        mysql::MySQL_Driver* driver;
        Connection* con;
        driver = mysql::get_mysql_driver_instance();
        con = driver->connect(HOST, USERNAME, PASSWORD);
        con->setSchema(DATABASE);

        // ����team_id�ж��Ƿ�Ϊuser_id
        PreparedStatement* pstmt;
        pstmt = con->prepareStatement("SELECT * FROM Teams WHERE team_id = ? AND creator_id = ?");
        pstmt->setInt(1, team_id);
        pstmt->setInt(2, user_id);
        ResultSet* res = pstmt->executeQuery();
        bool success = res->next();

        if (success) {
            // ����Ⱥ��
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

        // ����team_id�ж��Ƿ�Ϊuser_id
        PreparedStatement* pstmt;
        pstmt = con->prepareStatement("SELECT * FROM Teams WHERE team_id = ? AND creator_id = ?");
        pstmt->setInt(1, team_id);
        pstmt->setInt(2, user_id);
        ResultSet* res = pstmt->executeQuery();
        bool success = res->next();

        if (success) {
            // ����TeamMember�����������
            pstmt = con->prepareStatement("DELETE FROM TeamMember WHERE group_id = ?");
            pstmt->setInt(1, team_id);
            pstmt->execute();

            // ����Teams�����������
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

vector<int> getJoinedGroupIDs(int user_id) {
  vector<int> groupIDs;
  try {
    mysql::MySQL_Driver* driver;
    Connection* con;
    driver = mysql::get_mysql_driver_instance();
    con = driver->connect(HOST, USERNAME, PASSWORD);
    con->setSchema(DATABASE);
    PreparedStatement* pstmt;
    pstmt = con->prepareStatement("SELECT group_id FROM TeamMember WHERE member_id = ?");
    pstmt->setInt(1, user_id);
    ResultSet* res = pstmt->executeQuery();
    while (res->next()) {
      int group_id = res->getInt("group_id");
      groupIDs.push_back(group_id);
    }
    delete res;
    delete pstmt;
    delete con;
  }
  catch (SQLException& e) {
    cout << "SQL Exception: " << e.what() << endl;
  }
  return groupIDs;
}

