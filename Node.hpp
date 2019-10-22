#ifndef NODE_HPP
#define NODE_HPP

#include <vector>
#include <memory>

#include <SFML/Graphics.hpp>

#include "Message.hpp"

class Node;
typedef std::weak_ptr<Node> WeakNode;
typedef std::shared_ptr<Node> SharedNode;

class Node: public MessageHandler {
private:
    WeakNode parent;
protected:
public:
    std::string name;
    virtual void process(float delta) {};
    
    std::vector<SharedNode> children;
    
    void addChild(Node *child);
    SharedNode getChild(size_t idx);
    void setParent(SharedNode parent);
    
    bool hasParent();
    WeakNode getParent();
    template <class T>
    void handleMessage(Message<T> message) {
        MessageHandler::handleMessage(message);
    }
    
};

template<>
void Node::handleMessage(Message<sf::Event> message);

#endif