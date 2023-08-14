-- 创建用户表
CREATE TABLE Users (
user_id INT AUTO_INCREMENT PRIMARY KEY,
username VARCHAR(255) NOT NULL,
password VARCHAR(255) NOT NULL
);
-- 创建好友关系表
CREATE TABLE Friends (
friend_id INT AUTO_INCREMENT PRIMARY KEY,
user_id INT,
friend_user_id INT,
friend_nickname VARCHAR(255) DEFAULT NULL,
status VARCHAR(20),
FOREIGN KEY (user_id) REFERENCES Users(user_id),
FOREIGN KEY (friend_user_id) REFERENCES Users(user_id)
);
-- 创建私聊消息记录表
CREATE TABLE PrivateMessage (
message_id INT AUTO_INCREMENT PRIMARY KEY,
sender_id INT,
receiver_id INT,
content VARCHAR(255),
FOREIGN KEY (sender_id) REFERENCES Users(user_id),
FOREIGN KEY (receiver_id) REFERENCES Users(user_id)
);
-- 创建群组表
CREATE TABLE team (
team_id INT AUTO_INCREMENT PRIMARY KEY,
team_name VARCHAR(255),
creator_id INT,
FOREIGN KEY (creator_id) REFERENCES Users(user_id)
);
-- 创建群组成员表
CREATE TABLE TeamMembers (
team_member_id INT AUTO_INCREMENT PRIMARY KEY,
team_id INT,
member_id INT,
FOREIGN KEY (team_id) REFERENCES team(team_id),
FOREIGN KEY (member_id) REFERENCES Users(user_id)
);
-- 创建群聊消息记录表
CREATE TABLE TeamMessage (
message_id INT AUTO_INCREMENT PRIMARY KEY,
sender_id INT,
team_id INT,
content VARCHAR(255),
FOREIGN KEY (sender_id) REFERENCES Users(user_id),
FOREIGN KEY (team_id) REFERENCES team(team_id)
);