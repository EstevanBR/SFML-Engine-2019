#ifndef RECT_HPP
#define RECT_HPP

#include <SFML/Graphics.hpp>
#include "CollisionShape.hpp"
class CircleCollisionShape;

class RectCollisionShape:public sf::FloatRect, public CollisionShape {
public:
    sf::RectangleShape rectShape;
    
    RectCollisionShape(float left = 0, float top = 0, float width = 0, float height = 0);

    bool intersects(const CollisionShape &shape) const override;
    bool intersects(const CircleCollisionShape &circle) const;
    
    ~RectCollisionShape() override {};
};

#endif