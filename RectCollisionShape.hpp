#ifndef RECT_HPP
#define RECT_HPP

#include <SFML/Graphics.hpp>
#include "CollisionShape.hpp"
class CircleCollisionShape;

class RectCollisionShape:public sf::FloatRect, public CollisionShape {
public:
    RectCollisionShape(float left, float top, float width, float height):sf::FloatRect(left, top, width, height) {}
    bool intersects(const CollisionShape &shape) const override;
    bool intersects(const CircleCollisionShape &circle) const;
    ~RectCollisionShape() override {};
};

#endif