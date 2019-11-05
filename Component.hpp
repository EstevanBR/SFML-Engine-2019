#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "Node.hpp"
#include "Collection.hpp"

class Engine;

template<class Owner>
class Component: public Node {
private:
protected:
	Owner &owner;
	Component(Engine &engine, Owner &owner): owner(owner) {
		engine.tree.add_object();
	}
};

#endif