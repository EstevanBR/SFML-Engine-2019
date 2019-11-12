#include "Node.hpp"

Node::Node() {

}

void Node::_process(float delta) {
    process(delta);
    for (auto n: _nodes) {
        n->process(delta);
    }
}

Node::Node(std::shared_ptr<Node> parent) {
    setParent(parent);
}

bool Node::hasParent() {
    return !_parent.expired();
}
void Node::setParent(std::shared_ptr<Node> p) {
    _parent = std::weak_ptr<Node>(p);
}

std::weak_ptr<Node> Node::getParent()  {
    return _parent;
}

