#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "Node.hpp"
#include "Collection.hpp"
#include "Engine.hpp"

class Component: public Node {
private:
protected:
	Engine &engine;
	Component(Engine &engine);	
};

#endif