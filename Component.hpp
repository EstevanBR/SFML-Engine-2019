#ifndef COMPONENT_HPP
#define COMPONENT_HPP

class Node;

class Component {
public:
	Node &owner;
	Component(Node &owner);
};


#endif