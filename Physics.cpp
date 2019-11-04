#include <cmath>
#include "Physics.hpp"
#include "PhysicsComponent.hpp"
#include "RectCollisionShape.hpp"
#include "CircleCollisionShape.hpp"

void Physics::process(float delta) {
    //collisions.clear();
	for (auto a: objects) {
		for (auto b: objects) {
			if (a->id != b->id && checkCollision(a, b)) {
                
                a->_physicsComponent.collided(*b);
                b->_physicsComponent.collided(*a);
                //collisions.push_back(std::make_pair<size_t, size_t>(a->id, b->id);
                //collisions.push_back(std::map<size_t, size_t>(a->id, b->id));
                //collisions.push_back(std::map<size_t, size_t>(b->id, a->id));
                
                // collisions.insert_or_assign(a.get(), b.get());
                // collisions.insert_or_assign(b.get(), a.get());
                //collisions[a->id][b->id] = true;
                //a->_colliding.push_back(std::weak_ptr<CollisionShape>(b));
                //b->_colliding.push_back(std::weak_ptr<CollisionShape>(a));
            }
		}
	}
}

bool Physics::checkLayerCollision(const CollisionShape &a, const CollisionShape &b) {
    return a.getLayers() & b.getLayers() || a.getLayers() == b.getLayers();
}

bool Physics::checkCollision(std::shared_ptr<const CollisionShape> a, std::shared_ptr<const CollisionShape> b) {
    if (Physics::checkLayerCollision(*a, *b) == false) {
        return false;
    }
	auto ar = std::static_pointer_cast<const RectCollisionShape>(a);
	auto as = std::static_pointer_cast<const CircleCollisionShape>(a);
	
	auto br = std::static_pointer_cast<const RectCollisionShape>(b);
	auto bs = std::static_pointer_cast<const CircleCollisionShape>(b);

	if (ar.get() != nullptr && br.get() != nullptr) {
		return Physics::checkCollision(*ar,*br);
	} else if (ar.get() != nullptr && bs.get() != nullptr) {
		return Physics::checkCollision(*ar,*bs);
	} else if (as.get() != nullptr && bs.get() != nullptr) {
		return Physics::checkCollision(*as.get(),*bs.get());
	} else {
		return false;
	}
	
}

bool Physics::checkCollision(const RectCollisionShape &rectA, const RectCollisionShape &rectB) {
	return rectA.intersects(rectB);
}

bool Physics::checkCollision(const RectCollisionShape &rect, const CircleCollisionShape &circle) {
    if (rect.contains(circle.x, circle.y) and circle.radius > 0.f) {
        return true;
    } else {
        float testX;
        float testY;

        float x = rect.left;
        float y = rect.top;

        if (circle.x < x)                  testX = x;
        else if (circle.x > x+rect.width)  testX = x+rect.width;
        if (y < circle.y)                  testY = y;
        else if (circle.y > y+rect.height) testY = y+rect.height;

        float distX = circle.x-testX;
        float distY = circle.y-testY;
        float distance = sqrt((distX * distX) + (distY * distY));

        return distance <= circle.radius;
    }
	return false;
}

bool Physics::checkCollision(const CircleCollisionShape &circleA, const CircleCollisionShape &circleB) {
    float distX = circleB.x-circleA.x;
    float distY = circleB.y-circleA.y;
    float distance = sqrt((distX * distX) + (distY * distY));
    return distance <= circleA.radius+circleB.radius;
}
