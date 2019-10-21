#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <memory>
#include <vector>
#include <iostream>

template<class T>
class Message {
public:
    std::string name;
    T &data;
    Message(std::string name, T&data): data(data) {
        name = name;
    }
};

class MessageHandler {
public:
    template<class T>
    void handleMessage(Message<T> message) {
        std::cout << "got a message!" << std::endl;
    }
};

class MessageDispatcher {
public:
    std::vector<std::weak_ptr<MessageHandler>> handlers;
    template<class T>
    void dispatchMessage(Message<T> message) {
        std::cout << "dispatch a message!" << std::endl;
        for (auto handler: handlers) {
            handler.lock()->handleMessage<T>(message);
        }
    }
};

#endif