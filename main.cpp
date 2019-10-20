#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <math.h>

#include "GameWindow.hpp"
#include "Node.hpp"
#include "Collection.hpp"
#include "RectCollisionShape.hpp"
#include "CircleCollisionShape.hpp"

class Physics;

class PhysicsComponent: public Collection<std::unique_ptr<CollisionShape>> {
public:
    Node &owner;

    PhysicsComponent(Node &owner): owner(owner) {

    }
    ~PhysicsComponent() {}
    CollisionShape& getObject(size_t idx) {
        return *objects[idx].get();
    }
    // template<class T>
    // T &getObject(size_t idx) {
    //     return dynamic_cast<T &>(getObject(idx));
    // }
    template<class T2>
    T2 &getObject(size_t idx) {
        return dynamic_cast<T2 &>(getObject(idx));
    }

};
class Physics: public Collection<std::unique_ptr<PhysicsComponent>> {
private:
    
public:
    ~Physics() {}
    Physics() {}
    void process(float delta) {
        for (size_t i = 0; i < objects.size(); i++) {
            //auto p1 = getObject(i);
            for (size_t j = 0; j < objects.size(); j++) {
                if (i == j) {
                    continue;
                }
                //auto p2 = getObject(j);
            }
        }
    }

    size_t createObject(Node &owner) {
        objects.push_back(std::unique_ptr<PhysicsComponent>(new PhysicsComponent(owner)));
        return objects.size()-1;
    }
};

int main() {
    Physics physics;
    Node node;
    size_t pidx = physics.createObject(node);
    PhysicsComponent &physicsComponent = *physics.getObject(pidx);
    physicsComponent.objects.push_back(std::unique_ptr<CollisionShape>(new RectCollisionShape(0.f,0.f,100.f,100.f)));
    physicsComponent.objects.push_back(std::unique_ptr<CollisionShape>(new RectCollisionShape(0.f,0.f,50.f,50.f)));
    RectCollisionShape& rectShape1 = physicsComponent.getObject<RectCollisionShape>(0);
    RectCollisionShape& rectShape2 = physicsComponent.getObject<RectCollisionShape>(1);
    // physicsComponent.shape.type = PhysicsShape::RECTANGLE;
    // physicsComponent.shape.rectangle.height = 100.f;
    // physicsComponent.shape.rectangle.width = 20.f;

    sf::RectangleShape rect1;
    rect1.setPosition(sf::Vector2f(rectShape1.left, rectShape1.top));
    rect1.setSize(sf::Vector2f(rectShape1.width, rectShape1.height));
    rect1.setFillColor(sf::Color(0x00ff0060));

    sf::RectangleShape rect2;
    rect2.setPosition(sf::Vector2f(rectShape2.left, rectShape2.top));
    rect2.setSize(sf::Vector2f(rectShape2.width, rectShape2.height));
    rect2.setFillColor(sf::Color(0xff000060));

    std::cout << (rectShape1.intersects(rectShape2) ? "true" : "false") << std::endl;

    GameWindow window(sf::VideoMode(640, 480),sf::String("HelloWorld"));
    
    //window.addDrawable(std::shared_ptr<sf::Drawable>(new sf::CircleShape(100.f)));
    window.addDrawable(std::shared_ptr<sf::Drawable>(&rect1));
    window.addDrawable(std::shared_ptr<sf::Drawable>(&rect2));
    sf::Clock deltaClock;
    while (window.isOpen()) {
        float delta = deltaClock.restart().asSeconds();
        
        rect1.move(sf::Vector2f(10.f * delta, 0.0));
        rectShape1.left += 10.f * delta;
        
        if (rectShape1.intersects(rectShape2)) {
            rect1.setFillColor(sf::Color(0xffffffff));
            rect2.setFillColor(sf::Color(0xffffffff));
        } else {
            rect1.setFillColor(sf::Color(0x00ff0060));
            rect2.setFillColor(sf::Color(0xff000060));
        }
        window.process(delta);
    }

    return EXIT_SUCCESS;
}
