
#include <vector>
#include <iostream>
#include <math.h>
#include <functional>

#include <SFML/Graphics.hpp>

#include "GameWindow.hpp"
#include "Node.hpp"
#include "Collection.hpp"
#include "RectCollisionShape.hpp"
#include "CircleCollisionShape.hpp"

class Physics;
class Graphics;

class Component {
public:
	Node &owner;
	Component(Node &owner):owner(owner) {}
};
class GraphicsComponent: public Collection<sf::Drawable>, public Component {
public:
	GraphicsComponent(Node &owner):Component::Component(owner) {

	}
};
class PhysicsComponent: public Collection<CollisionShape>, public Component {
public:
	PhysicsComponent(Node &owner):Component::Component(owner) {

	}
	template<class T>
	std::shared_ptr<T> getObject(size_t idx) {
		return std::static_pointer_cast<T>(Collection<CollisionShape>::getObject(idx));
	}
	bool intersects(PhysicsComponent &other) {
		for (auto cs1: objects) {
			for (auto cs2: other.objects) {
				if (cs1->intersects(*cs2.get())) {
					return true;
				}
			}
		}
		return false;
	}

};

class Graphics:public Collection<GraphicsComponent> {
public:
	GameWindow &gameWindow;
	Graphics(GameWindow &gameWindow):gameWindow(gameWindow) {
		for (auto gc: objects) {
			for (auto d: gc->objects) {
				gameWindow.draw(*std::dynamic_pointer_cast<sf::Drawable>(d).get());	
			}
		}
	}
};

class Physics: public Collection<PhysicsComponent> {
private:
	
public:
	// ~Physics() {}
	// Physics() {}
	void process(float delta) {
		for (auto pc1: objects) {
			for (auto pc2: objects) {
				if (pc1.get() == pc2.get()) {
					continue;
				}
				
				if (pc1->intersects(*pc2.get())) {
					//
				} else {
					//
				}
			}
		}
	}

	size_t createObject(Node &owner) {
		objects.push_back(std::shared_ptr<PhysicsComponent>(new PhysicsComponent(owner)));
		return objects.size()-1;
	}
};

int main() {
	GameWindow window(sf::VideoMode(640, 480),sf::String("HelloWorld"));

	Physics physics;

	Node *node = new Node();

	window.handlers.push_back(std::weak_ptr<MessageHandler>(std::shared_ptr<MessageHandler>(node)));
	size_t pidx1 = physics.createObject(*node);
	size_t pidx2 = physics.createObject(*node);
	
	PhysicsComponent &physicsComponent1 = *physics.getObject(pidx1);
	physicsComponent1.objects.push_back(std::shared_ptr<CollisionShape>(new RectCollisionShape(0.f,0.f,100.f,100.f)));
	auto &rectShape1 = *physicsComponent1.getObject<RectCollisionShape>(0).get();

	PhysicsComponent &physicsComponent2 = *physics.getObject(pidx2);
	physicsComponent2.objects.push_back(std::shared_ptr<CollisionShape>(new RectCollisionShape(0.f,0.f,50.f,50.f)));
	auto &rectShape2 = *physicsComponent2.getObject<RectCollisionShape>(0).get();

	
	window.addDrawable(std::shared_ptr<sf::Drawable>(&rectShape1.rectShape));
	window.addDrawable(std::shared_ptr<sf::Drawable>(&rectShape2.rectShape));

	sf::Clock deltaClock;
	
	while (window.isOpen()) {
		float delta = deltaClock.restart().asSeconds();
		
		rectShape1.rectShape.move(sf::Vector2f(50.f * delta, 0.0));
		rectShape1.left += 50.f * delta;

		if (rectShape1.intersects(rectShape2)) {
			rectShape1.rectShape.setFillColor(sf::Color::Red);
			rectShape2.rectShape.setFillColor(sf::Color::Red);
		} else {
			rectShape1.rectShape.setFillColor(sf::Color::White);
			rectShape2.rectShape.setFillColor(sf::Color::White);
		}

		physics.process(delta);
		window.process(delta);
	}

	return EXIT_SUCCESS;
}

