-- 插入用户数据
INSERT INTO Users (username, password) VALUES
('user1', 'password1'),
('user2', 'password2'),
('user3', 'password3'),
('user4', 'password4'),
('user5', 'password5');
-- 插入好友关系数据
INSERT INTO Friends (user_id, friend_user_id, friend_nickname, status) VALUES
(1, 2, 'Friend1', 'Active'),
(1, 3, 'Friend2', 'Pending'),
(2, 4, 'Friend3', 'Active'),
(3, 5, 'Friend4', 'Active'),
(4, 5, 'Friend5', 'Pending');
-- 插入私聊消息记录数据
INSERT INTO PrivateMessage (sender_id, receiver_id, content) VALUES
(1, 2, 'Hello'),
(2, 1, 'Hi there'),
(1, 3, 'How are you?'),
(3, 1, 'I am good, thanks!');
-- 插入群组数据
INSERT INTO team (team_name, creator_id) VALUES
('Group1', 1),
('Group2', 2),
('Group3', 3);
-- 插入群组成员数据
INSERT INTO TeamMembers (team_id, member_id) VALUES
(1, 2),
(1, 3),
(2, 1),
(2, 3),
(3, 4),
(3, 5);
-- 插入群聊消息记录数据
INSERT INTO TeamMessage (sender_id, team_id, content) VALUES
(1, 1, 'Hello group'),
(2, 1, 'Hi everyone'),
(3, 2, 'How is everyone doing?'),
(4, 3, 'Good morning!');