#include "Node.hpp"

Node::Node() {

}

void Node::_process(float delta) {
    process(delta);
    for (auto n: objects) {
        n->process(delta);
    }
}

Node::Node(std::shared_ptr<Node> parent) {
    setParent(parent);
}

bool Node::hasParent() {
    return !parent.expired();
}
void Node::setParent(std::shared_ptr<Node> p) {
    //p->addObject<Node>(p);
    parent = std::weak_ptr<Node>(p);
}

std::weak_ptr<Node> Node::getParent()  {
    return parent;
}

