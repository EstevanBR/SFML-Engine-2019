#ifndef PHYSICS_HPP
#define PHYSICS_HPP

#include "Collection.hpp"

class Node;
class PhysicsComponent;
class CollisionShape;
class RectCollisionShape;
class CircleCollisionShape;

class Physics: public Collection<CollisionShape> {
private:
	friend class Game;
	void process(float delta);
	static bool checkLayerCollision(const CollisionShape &a, const CollisionShape &b);
	static bool checkCollision(const RectCollisionShape &a, const RectCollisionShape &b);
	static bool checkCollision(const RectCollisionShape &a, const CircleCollisionShape &b);
	static bool checkCollision(const CircleCollisionShape &a, const CircleCollisionShape &b);
public:
	static bool checkCollision(std::shared_ptr<const CollisionShape> a, std::shared_ptr<const CollisionShape> b);
};

#endif