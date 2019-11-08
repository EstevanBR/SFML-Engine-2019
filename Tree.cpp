#include "Tree.hpp"
#include "Node.hpp"

void Tree::process(float delta) {
    for (auto n: objects) {
        n->_process(delta);
    }
}