#ifndef PHYSICS_COMPONENT_HPP
#define PHYSICS_COMPONENT_HPP

#include "Component.hpp"
#include "Tree.hpp"

class Component;
class Physics;
class CollisionShape;

class PhysicsComponent: public Component {
    friend class Physics;
protected:
    PhysicsComponent(Physics &physics, Tree &tree);
    virtual void collided(CollisionShape &other) = 0;
};

template <class Owner>
class EntityPhysicsComponent: public PhysicsComponent {
    friend class Physics;
protected:
    Owner &owner;
    EntityPhysicsComponent(Physics &physics, Tree &tree, Owner &owner): PhysicsComponent(physics, tree), owner(owner) {}
};

#endif