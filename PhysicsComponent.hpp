#ifndef PHYSICS_COMPONENT_HPP
#define PHYSICS_COMPONENT_HPP

#include "Collection.hpp"
#include "Component.hpp"

class Node;
class CollisionShape;

class PhysicsComponent: public Collection<CollisionShape>, public Component {
private:
	friend class Physics;
	PhysicsComponent(Node &owner);
public:
	template <class T>
	size_t createObject() {
		objects.push_back(std::shared_ptr<CollisionShape>(static_cast<CollisionShape *>(new T)));
        return objects.size()-1;
    }
};

#endif