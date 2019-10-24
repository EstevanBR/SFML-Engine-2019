#include "Node.hpp"

Node::Node() {

}

Node::Node(std::shared_ptr<Node> parent) {
    setParent(parent);
}

bool Node::hasParent() {
    return !parent.expired();
}
void Node::setParent(std::shared_ptr<Node> p) {
    parent = std::weak_ptr<Node>(p);
}

std::weak_ptr<Node> Node::getParent()  {
    return parent;
}

std::shared_ptr<Node> Node::getChild(size_t idx) {
    return children[idx];
}

void Node::addChild(Node *child) {
    children.push_back(std::shared_ptr<Node>(child));
    child->setParent(children.back());
}

template<>
void MessageHandler::handleMessage(Message<sf::Event> message) {
    std::cout << "got a even message" << std::endl;
    std::cout << message.data.type << std::endl;
}
