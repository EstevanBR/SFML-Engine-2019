#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "Node.hpp"

class Tree;

class Component: public Node {
private:
protected:
	Component(Tree &tree);
};

#endif