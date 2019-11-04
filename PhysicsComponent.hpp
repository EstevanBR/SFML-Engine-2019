#ifndef PHYSICS_COMPONENT_HPP
#define PHYSICS_COMPONENT_HPP

#include "Component.hpp"
#include "Engine.hpp"

class Physics;

class PhysicsComponent: public Component {
    friend class Physics;
protected:
    PhysicsComponent(Engine &engine):Component(engine) {}
    virtual void collided(CollisionShape &other) = 0;
};

template <class Owner>
class EntityPhysicsComponent: public PhysicsComponent {
    friend class Physics;
protected:
    Owner &owner;
    EntityPhysicsComponent(Engine &engine, Owner &owner):PhysicsComponent(engine), owner(owner) {}
};

#endif