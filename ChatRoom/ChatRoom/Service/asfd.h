#include "MessageHandler.h"
#include "../serialize/DataStream.h"
#include "../serialize/Serializable.h"
#include "../net.cpp"
#include <iostream>

class Backend {
public:
    Backend() {
        // �ڹ��캯���н��г�ʼ�����������ʼ����Ϣ�������ӳ���ϵ
    }

    std::string HandleIncomingMessage(const std::string& message) {
        // ����ǰ����Ϣ����ȡ��Ϣ���͡���Ϣ��С������

        // ������Ϣ���ʹ�����Ӧ�Ĵ�����
        MessageHandler* handler = nullptr;
        if (messageType == LOG_IN) {
            handler = new Message_LOG_IN_Handler();
        }
        else if (messageType == 2) {
            handler = new MessageType2Handler();
        }
        else {
            // ����δ֪��Ϣ���͵��߼�
        }

        // ���ô�����Ĵ��������д���
        std::string response = handler->HandleMessage(messageContent);

        // �ͷŴ�������ڴ�
        delete handler;

        // ���ɻظ���Ϣ�����͸�ǰ��
        // ...

        return response;
    }

private:
    // ������Ա�����ͺ���...
};