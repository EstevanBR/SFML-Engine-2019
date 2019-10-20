#include <cmath>
#include "RectCollisionShape.hpp"
#include "CircleCollisionShape.hpp"

bool RectCollisionShape::intersects(const CollisionShape &shape) const {
    // if the circle origin is inside of the rectangle
    if (static_cast<const RectCollisionShape*>(&shape)) {
        auto &rect = *static_cast<const RectCollisionShape*>(&shape);
        return sf::FloatRect::intersects(rect);
    } else if (static_cast<const CircleCollisionShape*>(&shape)) {
        auto &circ = *static_cast<const CircleCollisionShape*>(&shape);
        return RectCollisionShape::intersects(circ);
    }

    return false;
}

bool RectCollisionShape::intersects(const CircleCollisionShape &circle) const {
    // if the circle origin is inside of the rectangle
    if (contains(circle.x, circle.y) and circle.radius > 0.f) {
        return true;
    } else {
        float testX;
        float testY;

        float x = left;
        float y = top;

        if (circle.x < x)             testX = x;
        else if (circle.x > x+width)  testX = x+width;
        if (y < circle.y)             testY = y;
        else if (circle.y > y+height) testY = y+height;

        float distX = circle.x-testX;
        float distY = circle.y-testY;
        float distance = sqrt((distX * distX) + (distY * distY));

        return distance <= circle.radius;
    }
}