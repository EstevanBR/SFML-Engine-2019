#ifndef CIRCLE_COLLISION_SHAPE_HPP
#define CIRCLE_COLLISION_SHAPE_HPP

#include "CollisionShape.hpp"
#include "Circle.hpp"

class RectCollisionShape;

class CircleCollisionShape: public CollisionShape, public FloatCircle {
public:
    CircleCollisionShape(PhysicsComponent &physicsComponent, float x = 0, float y = 0, float radius = 0);
};

#endif