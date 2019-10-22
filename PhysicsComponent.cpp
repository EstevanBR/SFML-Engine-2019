#include "PhysicsComponent.hpp"
#include "CollisionShape.hpp"

PhysicsComponent::PhysicsComponent(Node &owner):Component::Component(owner) {

}

bool PhysicsComponent::intersects(PhysicsComponent &other) {
    for (auto cs1: objects) {
        for (auto cs2: other.objects) {
            if (cs1->intersects(*cs2.get())) {
                return true;
            }
        }
    }
    return false;
}
