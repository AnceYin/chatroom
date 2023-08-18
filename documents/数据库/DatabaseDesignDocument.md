v1.0.0
1. Users表：//用户表
    - user_id（用户ID，主键，数据库自动生成）
    - username（用户名）
    - password（密码）
    - ip（用户登录设备ip）// 可以为空
    - port（用户登录设备端口）// 可以为空
2. Teams表： //团队表
    - team_id（群组ID，主键，数据库自动生成）
    - team_name（群组名）
    - creator_id（创建者ID，外键，关联Users表的user_id字段）
3. TeamMember表：//团队成员表
    - team_member_id（群组成员关系ID，主键，数据库自动生成）
    - group_id（群组ID，外键，关联Teams表的team_id字段）
    - member_id（成员ID，外键，关联Users表的user_id字段）


v1.0.1
1. Users表：//用户表
    - user_id（用户ID，主键，数据库自动生成）
    - username（用户名）
    - password（密码）
    - state (登录状态)
    - ip（用户登录设备ip）// 可以为空
    - port（用户登录设备端口）// 可以为空
4. Message表：//消息表，每条消息都存在数据库
    - message_id（消息ID，主键，数据库自动生成）
    - team_id（群组ID，外键，关联Teams表的team_id字段）
    - sender_id（发送者ID，外键，关联Users表的user_id字段）
    - content（消息内容）


1.1.0
5. Friend表：
    - friend_id（好友关系ID，主键，数据库自动生成）
    - user_id（用户ID，外键，关联User表的user_id字段）
    - friend_user_id（好友ID，外键，关联User表的user_id字段）
    - friend_nickname（好友备注昵称，默认显示好友用户名）
6. PrivateMessage表：
    - message_id（消息ID，主键，数据库自动生成）
    - sender_id（发送者ID，外键，关联User表的user_id字段）
    - receiver_id（接收者ID，外键，关联User表的user_id字段）
    - content（消息内容）

1.1.1
5. Friend表：
    - friend_id（好友关系ID，主键，数据库自动生成）
    - user_id（用户ID，外键，关联User表的user_id字段）
    - friend_user_id（好友ID，外键，关联User表的user_id字段）
    - friend_nickname（好友备注昵称，默认显示好友用户名）
    - status（好友关系状态，未添加/已添加/已删除）

