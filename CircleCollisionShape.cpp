#include <cmath>

#include "PhysicsComponent.hpp"
#include "CircleCollisionShape.hpp"
#include "RectCollisionShape.hpp"

CircleCollisionShape::CircleCollisionShape(PhysicsComponent &physicsComponent, float x, float y, float radius): FloatCircle(x,y,radius), CollisionShape(physicsComponent) {

}