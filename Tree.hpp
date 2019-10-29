#ifndef TREE_HPP
#define TREE_HPP

#include "Collection.hpp"
#include "Node.hpp"
class Node;

class Tree: public Collection<Node> {
private:
    friend class Game;
    std::string name = "Tree";
    void process(float delta) {
        for (auto n: objects) {
            n->_process(delta);
        }
    }
};

#endif