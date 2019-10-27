#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "Node.hpp"

template<class T>
class Component: public Node {
private:
	friend T;
	T &manager;
	Component(T &manager): manager(manager) {}
};

#endif