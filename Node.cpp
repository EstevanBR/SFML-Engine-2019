#include "Node.hpp"


bool Node::hasParent() {
    return !parent.expired();
}
void Node::setParent(SharedNode p) {
    parent = WeakNode(p);
}

WeakNode Node::getParent()  {
    return parent;
}

SharedNode Node::getChild(size_t idx) {
    return children[idx];
}

void Node::addChild(Node *child) {
    children.push_back(SharedNode(child));
    child->setParent(children.back());
}

template<>
void MessageHandler::handleMessage(Message<sf::Event> message) {
    std::cout << "got a even message" << std::endl;
    std::cout << message.data.type << std::endl;
}
