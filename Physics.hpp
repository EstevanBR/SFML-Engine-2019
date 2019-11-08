#ifndef PHYSICS_HPP
#define PHYSICS_HPP

#include "Collection.hpp"
#include "Node.hpp"
#include <map>
#include "CollisionShape.hpp"

class RectCollisionShape;
class CircleCollisionShape;

class Physics: public Node, public Collection<CollisionShape> {
private:
	friend class Game;
	void process(float delta) override;
	static bool checkLayerCollision(const CollisionShape &a, const CollisionShape &b);
	static bool checkCollision(const RectCollisionShape &a, const RectCollisionShape &b);
	static bool checkCollision(const RectCollisionShape &a, const CircleCollisionShape &b);
	static bool checkCollision(const CircleCollisionShape &a, const CircleCollisionShape &b);
public:
	static bool checkCollision(std::shared_ptr<const CollisionShape> a, std::shared_ptr<const CollisionShape> b);
};

#endif