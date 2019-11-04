#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "Node.hpp"
#include "Collection.hpp"

class Engine;

class Component: public Node {
private:
protected:
	Engine &engine;
	Component(Engine &engine);
};

#endif