#ifndef PHYSICS_HPP
#define PHYSICS_HPP

#include "Collection.hpp"

class Node;
class PhysicsComponent;

class Physics: public Collection<PhysicsComponent> {
private:
	friend class Game;
	void process(float delta);
public:
	size_t createObject(Node &owner);
};

#endif