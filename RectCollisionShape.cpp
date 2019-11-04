#include <cmath>
#include "PhysicsComponent.hpp"
#include "RectCollisionShape.hpp"
#include "CircleCollisionShape.hpp"

RectCollisionShape::RectCollisionShape(PhysicsComponent &physicsComponent, float left, float top, float width, float height): sf::FloatRect(left, top, width, height), CollisionShape(physicsComponent) {
    rectShape.setPosition(sf::Vector2f(left, top));
    rectShape.setSize(sf::Vector2f(width, height));
}
