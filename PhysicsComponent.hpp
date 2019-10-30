#ifndef PHYSICS_COMPONENT_HPP
#define PHYSICS_COMPONENT_HPP

#include "Component.hpp"

class Physics;

template<class Owner>
class PhysicsComponent: public Component<Physics, Owner> {
    friend class Physics;
protected:
    PhysicsComponent(Physics &physics, Owner &owner):Component<Physics, Owner>(physics, owner) {}
};

#endif