#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <memory>
#include <vector>
#include <iostream>

#include "Collection.hpp"

template<typename T>
struct Message {
private:
    std::string _name;
    T &_data;
public:
    const std::string &name = _name;
    const T &data = _data;
    
    Message(std::string name, T&data): _data(data) {
        name = name;
    }
};

template<typename T>
struct MessageHandler {
public:
    virtual void handleMessage(const Message<T> message) = 0;
};

template<typename T>
struct MessageDispatcher: public Collection<MessageHandler<T>> {
public:
    void dispatchMessage(Message<T> message) {
        for (auto handler: Collection<MessageHandler<T>>::objects) {
            handler->handleMessage(message);
        }
    }
};

#endif