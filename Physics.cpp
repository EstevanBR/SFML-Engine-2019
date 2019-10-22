#include "Physics.hpp"
#include "PhysicsComponent.hpp"

void Physics::process(float delta) {
	for (std::shared_ptr<PhysicsComponent> pc1: objects) {
		for (std::shared_ptr<PhysicsComponent> pc2: objects) {
			if (pc1.get() == pc2.get()) {
				continue;
			}
			
			if (pc1->intersects(*pc2.get())) {
				//
			} else {
				//
			}
		}
	}
}

size_t Physics::createObject(Node &owner) {
	objects.push_back(std::shared_ptr<PhysicsComponent>(new PhysicsComponent(owner)));
	return objects.size()-1;
}
