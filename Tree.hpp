#ifndef TREE_HPP
#define TREE_HPP

#include "Collection.hpp"

class Node;

class Tree: public Collection<Node> {
private:
    friend class Game;
    void process(float delta);
};

#endif