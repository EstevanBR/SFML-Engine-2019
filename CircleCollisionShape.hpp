#ifndef CIRCLE_COLLISION_SHAPE_HPP
#define CIRCLE_COLLISION_SHAPE_HPP

#include "CollisionShape.hpp"
#include "Circle.hpp"

class RectCollisionShape;

class CircleCollisionShape: public CollisionShape, public FloatCircle {
public:
    CircleCollisionShape(float x = 0, float y = 0, float radius = 0);
    bool intersects(const CollisionShape &shape) const override;
    bool intersects(const RectCollisionShape &rect) const;
    bool intersects(const CircleCollisionShape &other) const;
    ~CircleCollisionShape() override {};
};

#endif