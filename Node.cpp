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
