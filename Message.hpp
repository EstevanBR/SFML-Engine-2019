#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <memory>
#include <vector>
#include <iostream>

#include "Collection.hpp"

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

class MessageDispatcher: public Collection<MessageHandler> {
public:
    template<class T>
    void dispatchMessage(Message<T> message) {
        for (auto handler: Collection<MessageHandler>::objects) {
            handler->handleMessage<T>(message);
        }
    }
};

#endif