-- 插入Users表的假数据
INSERT INTO Users (username, password, ip, port) VALUES
('user1', 'password1', '192.168.0.1', 8080),
('user2', 'password2', '192.168.0.2', 8080),
('user3', 'password3', NULL, NULL);

-- 插入Teams表的假数据
INSERT INTO Teams (team_name, creator_id) VALUES
('team1', 10001),
('team2', 10002),
('team3', 10003);

-- 插入TeamMember表的假数据
INSERT INTO TeamMember (group_id, member_id) VALUES
(10000001, 10001),
(10000001, 10002),
(10000002, 10002),
(10000003, 10003);
