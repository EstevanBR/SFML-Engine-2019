#ifndef NODE_HPP
#define NODE_HPP

#include <vector>
#include <memory>
#include <assert.h>

class Node;
typedef std::weak_ptr<Node> WeakNode;
typedef std::shared_ptr<Node> SharedNode;

class Node {
private:
    WeakNode parent;
protected:
public:
    std::string name = "test";
    virtual void process(float delta) {};
    
    std::vector<SharedNode> children;
    
    void addChild(Node *child);
    SharedNode getChild(size_t idx);
    void setParent(SharedNode parent);
    
    bool hasParent();
    WeakNode getParent();
};

#endif