#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "CollisionShape.hpp"

class RectCollisionShape;

class CircleCollisionShape: public CollisionShape {
public:
    float x,y,radius;
    CircleCollisionShape(float x, float y, float radius) {
        x = x;
        y = y;
        radius = radius;
    }
    bool intersects(const CollisionShape &shape) const override;
    bool intersects(const RectCollisionShape &rect) const;
    bool intersects(const CircleCollisionShape &other) const;
    ~CircleCollisionShape() override {};
};

#endif