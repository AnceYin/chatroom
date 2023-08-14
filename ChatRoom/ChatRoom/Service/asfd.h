#include "MessageHandler.h"
#include "../serialize/DataStream.h"
#include "../serialize/Serializable.h"
#include <iostream>

class Backend {
public:
    Backend() {
        // �ڹ��캯���н��г�ʼ�����������ʼ����Ϣ�������ӳ���ϵ
    }

    DataStream HandleIncomingMessage(const std::string& message) {
        // ����ǰ����Ϣ����ȡ��Ϣ���͡���Ϣ��С������

        // ������Ϣ���ʹ�����Ӧ�Ĵ�����
        MessageHandler* handler = nullptr;
        if (messageType == 1) {
            handler = new MessageType1Handler();
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