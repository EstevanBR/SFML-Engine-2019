#ifndef TREE_HPP
#define TREE_HPP

#include "Collection.hpp"
#include "Node.hpp"
class Node;

class Tree: public Collection<Node> {
    friend class Game;
    void process(float delta) {
        for (auto n: objects) {
            n->process(delta);
        }
    }
};

#endif