-- 用户ID规定5位数初始ID为10000，群聊ID规定8位数初始ID为10000000

-- 创建Users表
CREATE TABLE Users (
  user_id INT(5) AUTO_INCREMENT PRIMARY KEY,
  username VARCHAR(50) NOT NULL,
  password VARCHAR(50) NOT NULL,
  ip VARCHAR(50),
  port INT,
  UNIQUE KEY unique_username (username)
);

ALTER TABLE Users AUTO_INCREMENT = 10000;

-- 创建Teams表
CREATE TABLE Teams (
  team_id INT(8) AUTO_INCREMENT PRIMARY KEY,
  team_name VARCHAR(50) NOT NULL,
  creator_id INT(5),
  FOREIGN KEY (creator_id) REFERENCES Users(user_id)
);

ALTER TABLE Teams AUTO_INCREMENT = 10000000;

-- 创建TeamMember表
CREATE TABLE TeamMember (
  team_member_id INT(8) AUTO_INCREMENT PRIMARY KEY,
  group_id INT(8),
  member_id INT(5),
  FOREIGN KEY (group_id) REFERENCES Teams(team_id),
  FOREIGN KEY (member_id) REFERENCES Users(user_id)
);


