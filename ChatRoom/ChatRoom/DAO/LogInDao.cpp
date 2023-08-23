#include "LogInDao.h"

// 登录函数
bool logIn(int user_id, string password)
{
    try
    {
        mysql::MySQL_Driver *driver;
        Connection *con;
        driver = mysql::get_mysql_driver_instance();
        con = driver->connect(HOST, USERNAME, PASSWORD);
        con->setSchema(DATABASE);
        Statement *stmt = con->createStatement();
        stmt->execute("SET NAMES 'utf8'");

        // 执行登录查询
        PreparedStatement *pstmt;
        pstmt = con->prepareStatement("SELECT * FROM Users WHERE user_id = ? AND password = ?");
        pstmt->setInt(1, user_id);
        pstmt->setString(2, password);
        ResultSet *res = pstmt->executeQuery();
        bool success = res->next();

        delete res;
        delete pstmt;
        delete con;
        return success;
    }
    catch (SQLException &e)
    {
        cout << "SQL Exception: " << e.what() << endl;
        return false;
    }
}

// 注册
// 返回值：成功返回用户ID，失败返回-1
int signIn(string username, string password)
{
    try
    {
        mysql::MySQL_Driver *driver = mysql::get_mysql_driver_instance();
        std::unique_ptr<Connection> con(driver->connect(HOST, USERNAME, PASSWORD));
        con->setSchema(DATABASE);

        // 创建Statement并设置字符集
        Statement *stmt = con->createStatement();
        stmt->execute("SET NAMES 'utf8'");

        // 使用参数化查询来防止SQL注入攻击
        std::unique_ptr<PreparedStatement> pstmt(con->prepareStatement("INSERT INTO Users (username, password) VALUES (?, ?)"));
        pstmt->setString(1, username);
        pstmt->setString(2, password);
        pstmt->execute();

        // 获取插入的用户ID
        std::unique_ptr<ResultSet> res(stmt->executeQuery("SELECT LAST_INSERT_ID()"));
        res->next();
        int user_id = res->getInt(1);

        return user_id;
    }
    catch (SQLException &e)
    {
        cout << "SQL Exception: " << e.what() << endl;
        return -1;
    }
}

// 更改用户名
bool changeUsername(int user_id, string new_username)
{
    try
    {
        mysql::MySQL_Driver *driver;
        Connection *con;
        driver = mysql::get_mysql_driver_instance();
        con = driver->connect(HOST, USERNAME, PASSWORD);
        con->setSchema(DATABASE);
        Statement *stmt = con->createStatement();
        stmt->execute("SET NAMES 'utf8'");
        PreparedStatement *pstmt;
        pstmt = con->prepareStatement("UPDATE Users SET username = ? WHERE user_id = ?");
        pstmt->setString(1, new_username);
        pstmt->setInt(2, user_id);
        pstmt->execute();
        delete pstmt;
        delete con;
        return true;
    }
    catch (SQLException &e)
    {
        cout << "SQL Exception: " << e.what() << endl;
        return false;
    }
}

// 更改密码
bool changePassword(int user_id, string password, string new_password)
{
    try
    {
        mysql::MySQL_Driver *driver;
        Connection *con;
        driver = mysql::get_mysql_driver_instance();
        con = driver->connect(HOST, USERNAME, PASSWORD);
        con->setSchema(DATABASE);
        Statement *stmt = con->createStatement();
        stmt->execute("SET NAMES 'utf8'");

        // 验证密码
        PreparedStatement *pstmt;
        pstmt = con->prepareStatement("SELECT * FROM Users WHERE user_id = ? AND password = ?");
        pstmt->setInt(1, user_id);
        pstmt->setString(2, password);
        ResultSet *res = pstmt->executeQuery();
        bool success = res->next();

        if (success)
        {
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
    catch (SQLException &e)
    {
        cout << "SQL Exception: " << e.what() << endl;
        return false;
    }
}

// 创建群聊
// 返回值：成功返回群聊ID，失败返回-1
int createTeam(int user_id, string team_name)
{
    try
    {
        mysql::MySQL_Driver *driver;
        Connection *con;
        driver = mysql::get_mysql_driver_instance();
        con = driver->connect(HOST, USERNAME, PASSWORD);
        con->setSchema(DATABASE);
        Statement *stmt = con->createStatement();
        stmt->execute("SET NAMES 'utf8'");
        PreparedStatement *pstmt;
        pstmt = con->prepareStatement("INSERT INTO Teams (team_name, creator_id) VALUES (?, ?)");
        pstmt->setString(1, team_name);
        pstmt->setInt(2, user_id);
        pstmt->execute();
        stmt = con->createStatement();
        ResultSet *res = stmt->executeQuery("SELECT LAST_INSERT_ID()");
        res->next();
        int team_id = res->getInt(1);
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
    catch (SQLException &e)
    {
        cout << "SQL Exception: " << e.what() << endl;
        return -1;
    }
}

// 加入群聊
bool joinTeam(int user_id, int team_id)
{
    // 检查用户是否已经在群聊中
    if (queryUserInTeam(user_id, team_id))
    {
        cout << "User is already in the team." << endl;
        return false;
    }
    try
    {
        mysql::MySQL_Driver *driver;
        Connection *con;
        driver = mysql::get_mysql_driver_instance();
        con = driver->connect(HOST, USERNAME, PASSWORD);
        con->setSchema(DATABASE);
        Statement *stmt = con->createStatement();
        stmt->execute("SET NAMES 'utf8'");
        PreparedStatement *pstmt;
        pstmt = con->prepareStatement("INSERT INTO TeamMember (group_id, member_id) VALUES (?, ?)");
        pstmt->setInt(1, team_id);
        pstmt->setInt(2, user_id);
        pstmt->execute();
        delete pstmt;
        delete con;
        return true;
    }
    catch (SQLException &e)
    {
        cout << "SQL Exception: " << e.what() << endl;
        return false;
    }
}

// 发消息
// 由MessageSentList调用, 无需返回值给用户
vector<int> sendMessage(int user_id, int team_id)
{
    vector<int> forwardingIDs;
    try
    {
        mysql::MySQL_Driver *driver;
        Connection *con;
        driver = mysql::get_mysql_driver_instance();
        con = driver->connect(HOST, USERNAME, PASSWORD);
        con->setSchema(DATABASE);
        Statement *stmt = con->createStatement();
        stmt->execute("SET NAMES 'utf8'");
        PreparedStatement *pstmt;
        pstmt = con->prepareStatement("SELECT member_id FROM TeamMember WHERE group_id = ? AND member_id != ?");
        pstmt->setInt(1, team_id);
        pstmt->setInt(2, user_id);
        ResultSet *res = pstmt->executeQuery();
        while (res->next())
        {
            int member_id = res->getInt("member_id");
            forwardingIDs.push_back(member_id);
        }
        delete res;
        delete pstmt;
        delete con;
    }
    catch (SQLException &e)
    {
        cout << "SQL Exception: " << e.what() << endl;
    }
    return forwardingIDs;
}

// 更改群名
bool changeTeamName(int user_id, int team_id, string new_team_name)
{
    try
    {
        mysql::MySQL_Driver *driver;
        Connection *con;
        driver = mysql::get_mysql_driver_instance();
        con = driver->connect(HOST, USERNAME, PASSWORD);
        con->setSchema(DATABASE);
        Statement *stmt = con->createStatement();
        stmt->execute("SET NAMES 'utf8'");
        PreparedStatement *pstmt;
        pstmt = con->prepareStatement("SELECT * FROM Teams WHERE team_id = ? AND creator_id = ?");
        pstmt->setInt(1, team_id);
        pstmt->setInt(2, user_id);
        ResultSet *res = pstmt->executeQuery();
        if (res->next())
        {
            pstmt = con->prepareStatement("UPDATE Teams SET team_name = ? WHERE team_id = ?");
            pstmt->setString(1, new_team_name);
            pstmt->setInt(2, team_id);
            pstmt->execute();
        }
        delete res;
        delete pstmt;
        delete con;
        return true;
    }
    catch (SQLException &e)
    {
        cout << "SQL Exception: " << e.what() << endl;
        return false;
    }
}

// 删除群聊
bool deleteTeam(int user_id, int team_id)
{
    try
    {
        mysql::MySQL_Driver *driver;
        Connection *con;
        driver = mysql::get_mysql_driver_instance();
        con = driver->connect(HOST, USERNAME, PASSWORD);
        con->setSchema(DATABASE);
        Statement *stmt = con->createStatement();
        stmt->execute("SET NAMES 'utf8'");
        PreparedStatement *pstmt;
        pstmt = con->prepareStatement("SELECT * FROM Teams WHERE team_id = ? AND creator_id = ?");
        pstmt->setInt(1, team_id);
        pstmt->setInt(2, user_id);
        ResultSet *res = pstmt->executeQuery();
        if (res->next())
        {
            pstmt = con->prepareStatement("DELETE FROM TeamMember WHERE group_id = ?");
            pstmt->setInt(1, team_id);
            pstmt->execute();
            pstmt = con->prepareStatement("DELETE FROM Teams WHERE team_id = ?");
            pstmt->setInt(1, team_id);
            pstmt->execute();
        }
        delete res;
        delete pstmt;
        delete con;
        return true;
    }
    catch (SQLException &e)
    {
        cout << "SQL Exception: " << e.what() << endl;
        return false;
    }
}

// 查询指定用户ID所在的所有群聊ID
// 查询不到返回空数组
vector<int> queryTeamsByUserID(int user_id)
{
    vector<int> groupIDs;
    try
    {
        mysql::MySQL_Driver *driver;
        Connection *con;
        driver = mysql::get_mysql_driver_instance();
        con = driver->connect(HOST, USERNAME, PASSWORD);
        con->setSchema(DATABASE);
        Statement *stmt = con->createStatement();
        stmt->execute("SET NAMES 'utf8'");
        PreparedStatement *pstmt;
        pstmt = con->prepareStatement("SELECT group_id FROM TeamMember WHERE member_id = ?");
        pstmt->setInt(1, user_id);
        ResultSet *res = pstmt->executeQuery();
        while (res->next())
        {
            int group_id = res->getInt("group_id");
            groupIDs.push_back(group_id);
        }
        delete res;
        delete pstmt;
        delete con;
    }
    catch (SQLException &e)
    {
        cout << "SQL Exception: " << e.what() << endl;
    }
    return groupIDs;
}

// 查询指定群聊ID所有成员用户ID
// 查询不到返回空数组
vector<int> queryUsersByTeamID(int team_id)
{
    vector<int> memberIDs;
    try
    {
        mysql::MySQL_Driver *driver;
        Connection *con;
        driver = mysql::get_mysql_driver_instance();
        con = driver->connect(HOST, USERNAME, PASSWORD);
        con->setSchema(DATABASE);
        Statement *stmt = con->createStatement();
        stmt->execute("SET NAMES 'utf8'");
        PreparedStatement *pstmt;
        pstmt = con->prepareStatement("SELECT member_id FROM TeamMember WHERE group_id = ?");
        pstmt->setInt(1, team_id);
        ResultSet *res = pstmt->executeQuery();
        while (res->next())
        {
            int member_id = res->getInt("member_id");
            memberIDs.push_back(member_id);
        }
        delete res;
        delete pstmt;
        delete con;
    }
    catch (SQLException &e)
    {
        cout << "SQL Exception: " << e.what() << endl;
    }
    return memberIDs;
}

// 查询指定用户ID创建的所有群聊ID
// 查询不到返回空数组
vector<int> queryTeamsByCreatorID(int user_id)
{
    vector<int> teamIDs;
    try
    {
        mysql::MySQL_Driver *driver;
        Connection *con;
        driver = mysql::get_mysql_driver_instance();
        con = driver->connect(HOST, USERNAME, PASSWORD);
        con->setSchema(DATABASE);
        Statement *stmt = con->createStatement();
        stmt->execute("SET NAMES 'utf8'");
        PreparedStatement *pstmt;
        pstmt = con->prepareStatement("SELECT team_id FROM Teams WHERE creator_id = ?");
        pstmt->setInt(1, user_id);
        ResultSet *res = pstmt->executeQuery();
        while (res->next())
        {
            int team_id = res->getInt("team_id");
            teamIDs.push_back(team_id);
        }
        delete res;
        delete pstmt;
        delete con;
    }
    catch (SQLException &e)
    {
        cout << "SQL Exception: " << e.what() << endl;
    }
    return teamIDs;
}

// 查询指定群聊ID创建者ID
// 群聊ID无效或异常返回-1
int queryCreatorByTeamID(int team_id)
{
    int creator_id = -1;
    try
    {
        mysql::MySQL_Driver *driver;
        Connection *con;
        driver = mysql::get_mysql_driver_instance();
        con = driver->connect(HOST, USERNAME, PASSWORD);
        con->setSchema(DATABASE);
        Statement *stmt = con->createStatement();
        stmt->execute("SET NAMES 'utf8'");
        PreparedStatement *pstmt;
        pstmt = con->prepareStatement("SELECT creator_id FROM Teams WHERE team_id = ?");
        pstmt->setInt(1, team_id);
        ResultSet *res = pstmt->executeQuery();
        if (res->next())
        {
            creator_id = res->getInt("creator_id");
        }
        delete res;
        delete pstmt;
        delete con;
    }
    catch (SQLException &e)
    {
        cout << "SQL Exception: " << e.what() << endl;
        return -1;
    }
    return creator_id;
}

// 查询指定用户ID用户名
// 用户ID无效或异常返回空串
string queryUsernameByUserID(int user_id)
{
    string username = "";
    try
    {
        mysql::MySQL_Driver *driver;
        Connection *con;
        driver = mysql::get_mysql_driver_instance();
        con = driver->connect(HOST, USERNAME, PASSWORD);
        con->setSchema(DATABASE);
        Statement *stmt = con->createStatement();
        stmt->execute("SET NAMES 'utf8'");
        PreparedStatement *pstmt;
        pstmt = con->prepareStatement("SELECT username FROM Users WHERE user_id = ?");
        pstmt->setInt(1, user_id);
        ResultSet *res = pstmt->executeQuery();
        if (res->next())
        {
            username = res->getString("username");
        }
        delete res;
        delete pstmt;
        delete con;
    }
    catch (SQLException &e)
    {
        cout << "SQL Exception: " << e.what() << endl;
    }
    return username;
}

// 查询指定用户名所有用户ID
// 查询不到返回空数组
vector<int> queryUserIDsByUsername(string username)
{
    vector<int> userIDs;
    try
    {
        mysql::MySQL_Driver *driver;
        Connection *con;
        driver = mysql::get_mysql_driver_instance();
        con = driver->connect(HOST, USERNAME, PASSWORD);
        con->setSchema(DATABASE);
        Statement *stmt = con->createStatement();
        stmt->execute("SET NAMES 'utf8'");
        PreparedStatement *pstmt;
        pstmt = con->prepareStatement("SELECT user_id FROM Users WHERE username = ?");
        pstmt->setString(1, username);
        ResultSet *res = pstmt->executeQuery();
        while (res->next())
        {
            int user_id = res->getInt("user_id");
            userIDs.push_back(user_id);
        }
        delete res;
        delete pstmt;
        delete con;
    }
    catch (SQLException &e)
    {
        cout << "SQL Exception: " << e.what() << endl;
    }
    return userIDs;
}

// 查询指定群聊ID群名
// 群聊ID无效或异常返回空串
string queryTeamNameByTeamID(int team_id)
{
    string team_name = "";
    try
    {
        mysql::MySQL_Driver *driver;
        Connection *con;
        driver = mysql::get_mysql_driver_instance();
        con = driver->connect(HOST, USERNAME, PASSWORD);
        con->setSchema(DATABASE);
        Statement *stmt = con->createStatement();
        stmt->execute("SET NAMES 'utf8'");
        PreparedStatement *pstmt;
        pstmt = con->prepareStatement("SELECT team_name FROM Teams WHERE team_id = ?");
        pstmt->setInt(1, team_id);
        ResultSet *res = pstmt->executeQuery();
        if (res->next())
        {
            team_name = res->getString("team_name");
        }
        delete res;
        delete pstmt;
        delete con;
    }
    catch (SQLException &e)
    {
        cout << "SQL Exception: " << e.what() << endl;
    }
    return team_name;
}

// 查询指定群名所有群聊ID
// 查询不到返回空数组
vector<int> queryTeamIDsByTeamName(string team_name)
{
    vector<int> teamIDs;
    try
    {
        mysql::MySQL_Driver *driver;
        Connection *con;
        driver = mysql::get_mysql_driver_instance();
        con = driver->connect(HOST, USERNAME, PASSWORD);
        con->setSchema(DATABASE);
        Statement *stmt = con->createStatement();
        stmt->execute("SET NAMES 'utf8'");
        PreparedStatement *pstmt;
        pstmt = con->prepareStatement("SELECT team_id FROM Teams WHERE team_name = ?");
        pstmt->setString(1, team_name);
        ResultSet *res = pstmt->executeQuery();
        while (res->next())
        {
            int team_id = res->getInt("team_id");
            teamIDs.push_back(team_id);
        }
        delete res;
        delete pstmt;
        delete con;
    }
    catch (SQLException &e)
    {
        cout << "SQL Exception: " << e.what() << endl;
    }
    return teamIDs;
}

// 删除账号
bool deleteUser(int user_id, string password)
{
    try
    {
        mysql::MySQL_Driver *driver;
        Connection *con;
        driver = mysql::get_mysql_driver_instance();
        con = driver->connect(HOST, USERNAME, PASSWORD);
        con->setSchema(DATABASE);
        Statement *stmt = con->createStatement();
        stmt->execute("SET NAMES 'utf8'");
        PreparedStatement *pstmt;
        pstmt = con->prepareStatement("DELETE FROM Users WHERE user_id = ? AND password = ?");
        pstmt->setInt(1, user_id);
        pstmt->setString(2, password);
        pstmt->executeUpdate();
        delete pstmt;
        delete con;
        return true;
    }
    catch (SQLException &e)
    {
        cout << "SQL Exception: " << e.what() << endl;
        return false;
    }
}

// 退出群聊
bool leaveTeam(int user_id, int team_id)
{
    try
    {
        mysql::MySQL_Driver *driver;
        Connection *con;
        driver = mysql::get_mysql_driver_instance();
        con = driver->connect(HOST, USERNAME, PASSWORD);
        con->setSchema(DATABASE);
        Statement *stmt = con->createStatement();
        stmt->execute("SET NAMES 'utf8'");
        PreparedStatement *pstmt;
        pstmt = con->prepareStatement("DELETE FROM TeamMember WHERE member_id = ? AND group_id = ?");
        pstmt->setInt(1, user_id);
        pstmt->setInt(2, team_id);
        pstmt->executeUpdate();
        delete pstmt;
        delete con;
        return true;
    }
    catch (SQLException &e)
    {
        cout << "SQL Exception: " << e.what() << endl;
        return false;
    }
}

// 转交创建者身份
bool transferCreator(int user_id, int to_user_id)
{
    int result = 0;
    try
    {
        mysql::MySQL_Driver *driver;
        Connection *con;
        driver = mysql::get_mysql_driver_instance();
        con = driver->connect(HOST, USERNAME, PASSWORD);
        con->setSchema(DATABASE);
        Statement *stmt = con->createStatement();
        stmt->execute("SET NAMES 'utf8'");
        PreparedStatement *pstmt;
        pstmt = con->prepareStatement("UPDATE Teams SET creator_id = ? WHERE creator_id = ?");
        pstmt->setInt(1, to_user_id);
        pstmt->setInt(2, user_id);
        pstmt->executeUpdate();
        delete pstmt;
        delete con;
        return true;
    }
    catch (SQLException &e)
    {
        cout << "SQL Exception: " << e.what() << endl;
        return false;
    }
}

// 查询用户是否在指定群聊
bool queryUserInTeam(int user_id, int team_id)
{
    try
    {
        mysql::MySQL_Driver *driver;
        Connection *con;
        driver = mysql::get_mysql_driver_instance();
        con = driver->connect(HOST, USERNAME, PASSWORD);
        con->setSchema(DATABASE);
        Statement *stmt = con->createStatement();
        stmt->execute("SET NAMES 'utf8'");
        PreparedStatement *pstmt;
        pstmt = con->prepareStatement("SELECT COUNT(*) FROM TeamMember WHERE group_id = ? AND member_id = ?");
        pstmt->setInt(1, team_id);
        pstmt->setInt(2, user_id);
        ResultSet *res = pstmt->executeQuery();
        int count = 0;
        if (res->next())
        {
            count = res->getInt(1);
        }
        delete res;
        delete pstmt;
        delete con;
        return count > 0;
    }
    catch (SQLException &e)
    {
        cout << "SQL Exception: " << e.what() << endl;
        return false;
    }
}