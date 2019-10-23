#ifndef NODE_HPP
#define NODE_HPP

#include <vector>
#include <memory>

#include <SFML/Graphics.hpp>

#include "Message.hpp"

class Node: public MessageHandler {
private:
    std::weak_ptr<Node> parent;
protected:
public:
    std::string name;
    virtual void process(float delta) {};
    
    std::vector<std::shared_ptr<Node>> children;
    
    void addChild(Node *child);
    std::shared_ptr<Node> getChild(size_t idx);
    void setParent(std::shared_ptr<Node> parent);
    
    bool hasParent();
    std::weak_ptr<Node> getParent();
    template <class T>
    void handleMessage(Message<T> message) {
        MessageHandler::handleMessage(message);
    }
    
};

template<>
void Node::handleMessage(Message<sf::Event> message);

#endif