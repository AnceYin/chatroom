// ChatRoom.cpp: 定义应用程序的入口点。
//
//保存客户端的信息
#include <iostream>
#include <string>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <map>

#include "config/server_config.h"

#include "serialize/DataStream.h"
#include "serialize/Serializable.h"

#include "Service/MessageHandler.h"

using namespace yazi::serialize;

struct Client {
	int sockfd;
	int userid;//用户编号
};

int main(){
	// 创建监听Socket
	int socketfd = socket(AF_INET, SOCK_STREAM, 0);
	if (socketfd < 0) {
		perror("socket create error");
	}

	// 绑定本地ip和端口
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = htons(55369);

	std::cout << addr.sin_addr.s_addr << std::endl << socketfd;

	int ret = bind(socketfd, (struct sockaddr*)&addr, sizeof(addr));
	if (ret < 0) {
		perror("bind error 11");
		return -1;
	}

	// 设为监听状态
	ret = listen(socketfd, 1024);
	if (ret < 0) {
		perror("listen error");
	}

	//创健epo11实例
	int epld = epoll_create1(0);
	if (epld < 0) {
		perror("epoll create error");
		return -1;
	}

	// 将监听的Socket加入epoll
	struct epoll_event ev;
	ev.events = EPOLLIN;
	ev.data.fd = socketfd;

	ret = epoll_ctl(epld, EPOLL_CTL_ADD, socketfd, &ev);
	if (ret < 0) {
		perror("epoll_ctl error");
	}
	// 保存所有客户端信息
	std::map<int, Client> clients;

	// 循环监听
	while (1) {
		struct epoll_event evs[MAX_CONNECTIONS];
		int n = epoll_wait(epld, evs, MAX_CONNECTIONS, -1);

		printf("11111");

		if (n < 0) {
			printf("epoll_wait error");
			break;
		}

		for (int i = 0; i < n; i++) {
			int fd = evs[i].data.fd;
			if (fd == socketfd) {
				struct sockaddr_in client_addr;
				socklen_t client_addr_len = sizeof(client_addr);
				int client_sockfd = accept(socketfd, (struct sockaddr*)&client_sockfd, &client_addr_len);
				if (client_sockfd < 0) {
					printf("连接出错");
					continue;
				}

				// 将客户端Socket加入epoll
				struct epoll_event ev_client;
				ev_client.events = EPOLLIN;
				ev_client.data.fd = client_sockfd;
				ret = epoll_ctl(epld, EPOLL_CTL_ADD, client_sockfd, &ev_client);
				if (ret < 0) {
					printf("epoll_ctl error");
					return -1;
				}
				printf("%s正在连接", client_addr.sin_addr.s_addr);

				// 保存客户信息
				Client client;
				client.sockfd = client_sockfd;
				client.userid = 114514;

				clients[client_sockfd] = client;
			} 
			else {// 客户端端口发来消息
				char buffer[1024];
				int n = read(fd, buffer, 1024);
				if (n < 0) {
					// 发生错误
					break;
				} 
				else if (n == 0) {
					// 客户端此时断开连接
					close(fd);
					epoll_ctl(epld, EPOLL_CTL_DEL, fd, 0);

					clients.erase(fd);
				}
				else {
					// 收到客户端消息
					std::string msg(buffer, n);
					// 判断消息类型

					DataStream ds(msg);

					int msgType, msgSize;
					ds >> msgType >> msgSize;

					// 选择处理函数
					MessageHandlerIndustry msgHandIn(msgType, msgSize, ds);

					MessageHandler* handler = msgHandIn.CreateHandleMessage();
					DataStream back_ds = handler->HandleMessage(msgSize, ds);
					vector<int> sendList = handler->MessageSentList(msgSize, ds);
					
					for (auto& c : clients) {
						write(c.first, ds.data(), ds.size());
					}
					// 根据返回发送名单发送报文
					for (auto& c : sendList) {
						for (auto& client : clients) {
							if (client.second.userid == c) {
								write(client.first, back_ds.data(), back_ds.size());
							}
						}
					}
					delete handler;
				}
			}
		}

	}
	// 关闭epoll实例
	close(epld);
	close(socketfd);
}
