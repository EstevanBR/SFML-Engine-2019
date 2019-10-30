#ifndef NODE_HPP
#define NODE_HPP

#include <memory>

#include "Collection.hpp"

class Node {
private:
    std::weak_ptr<Node> parent;
    void _process(float delta);
    std::vector<std::shared_ptr<Node>> nodes;
protected:
    friend class Tree;
    virtual void process(float delta) = 0;
public:
    Node();
    Node(std::shared_ptr<Node> parent);
    
    void setParent(std::shared_ptr<Node> parent);
    
    bool hasParent();
    std::weak_ptr<Node> getParent();
    
};

#endif