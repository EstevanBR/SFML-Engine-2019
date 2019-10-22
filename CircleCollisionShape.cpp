#include <cmath>

#include "CircleCollisionShape.hpp"
#include "RectCollisionShape.hpp"

CircleCollisionShape::CircleCollisionShape(float x, float y, float radius): FloatCircle(x,y,radius) {

}

bool CircleCollisionShape::intersects(const CollisionShape &shape) const {
    // if the circle origin is inside of the rectangle
    if (static_cast<const RectCollisionShape*>(&shape)) {
        auto &rect = *static_cast<const RectCollisionShape*>(&shape);
        return CircleCollisionShape::intersects(rect);
    } else if (static_cast<const CircleCollisionShape*>(&shape)) {
        auto &circ = *static_cast<const CircleCollisionShape*>(&shape);
        return CircleCollisionShape::intersects(circ);
    }

    return false;
}

bool CircleCollisionShape::intersects(const RectCollisionShape &rect) const {
    return rect.intersects(*this);
}
bool CircleCollisionShape::intersects(const CircleCollisionShape &other) const {
    float distX = other.x-x;
    float distY = other.y-y;
    float distance = sqrt((distX * distX) + (distY * distY));
    return distance <= radius+other.radius;
}


    
