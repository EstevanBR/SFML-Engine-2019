#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "Node.hpp"
#include "Collection.hpp"

template<class Subsystem, class Owner>
class Component: public Node {
private:
	friend Subsystem;
protected:
	Subsystem &subsystem;
	Owner &owner;
	Component(Subsystem &subsystem, Owner &owner): owner(owner), subsystem(subsystem) {}
};

#endif