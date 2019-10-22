#ifndef RECT_HPP
#define RECT_HPP

#include <SFML/Graphics.hpp>
#include "CollisionShape.hpp"
class CircleCollisionShape;

class RectCollisionShape:public sf::FloatRect, public CollisionShape {
public:
    sf::RectangleShape rectShape;
    RectCollisionShape(float left, float top, float width, float height):sf::FloatRect(left, top, width, height) {
        rectShape.setPosition(sf::Vector2f(left, top));
        rectShape.setSize(sf::Vector2f(width, height));
    }
    bool intersects(const CollisionShape &shape) const override;
    bool intersects(const CircleCollisionShape &circle) const;
    ~RectCollisionShape() override {};
};

#endif