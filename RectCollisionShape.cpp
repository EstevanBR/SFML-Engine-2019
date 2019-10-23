#include <cmath>
#include "RectCollisionShape.hpp"
#include "CircleCollisionShape.hpp"

RectCollisionShape::RectCollisionShape(float left, float top, float width, float height): sf::FloatRect(left, top, width, height) {
    rectShape.setPosition(sf::Vector2f(left, top));
    rectShape.setSize(sf::Vector2f(width, height));
}
