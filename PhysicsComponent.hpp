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
	template<class T>
	std::shared_ptr<T> getObject(size_t idx) {
		assert(idx < objects.size());
		if (idx >= objects.size()) {
			return std::shared_ptr<T>(nullptr);
		} else {
			return std::static_pointer_cast<T>(Collection<CollisionShape>::getObject(idx));
		}
	}
	template <class T>
	size_t createObject() {
		objects.push_back(std::shared_ptr<CollisionShape>(static_cast<CollisionShape *>(new T)));
        return objects.size()-1;
    }
};

#endif