#include "MessageHandler.h"
#include "../serialize/DataStream.h"
#include "../serialize/Serializable.h"
#include "../net.cpp"
#include <iostream>

class Backend {
public:
    Backend() {
        // 在构造函数中进行初始化操作，如初始化消息处理类的映射关系
    }

    std::string HandleIncomingMessage(const std::string& message) {
        // 解析前端信息，获取消息类型、消息大小和内容

        // 根据消息类型创建相应的处理类
        MessageHandler* handler = nullptr;
        if (messageType == LOG_IN) {
            handler = new Message_LOG_IN_Handler();
        }
        else if (messageType == 2) {
            handler = new MessageType2Handler();
        }
        else {
            // 处理未知消息类型的逻辑
        }

        // 调用处理类的处理函数进行处理
        std::string response = handler->HandleMessage(messageContent);

        // 释放处理类的内存
        delete handler;

        // 生成回复消息并发送给前端
        // ...

        return response;
    }

private:
    // 其他成员变量和函数...
};