#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <math.h>

#include "GameWindow.hpp"
#include "Node.hpp"
#include "Collection.hpp"

class Circle;

class Rect:public sf::FloatRect {
public:
    bool intersects(const Circle &circle) const;
};

class Circle {
public:
    float x,y,radius;
    bool intersects(const Rect &rect) const;
    bool intersects(const Circle &other) const;
};

bool Circle::intersects(const Rect &rect) const {
    return rect.intersects(*this);
}
bool Circle::intersects(const Circle &other) const {
    float distX = other.x-x;
    float distY = other.y-y;
    float distance = sqrt((distX * distX) + (distY * distY));
    return distance <= radius+other.radius;
}


bool Rect::intersects(const Circle &circle) const {
    // if the circle origin is inside of the rectangle
    if (contains(circle.x, circle.y) and circle.radius > 0.f) {
        return true;
    } else {
        float testX;
        float testY;

        float x = left;
        float y = top;

        if (circle.x < x)             testX = x;
        else if (circle.x > x+width)  testX = x+width;
        if (y < circle.y)             testY = y;
        else if (circle.y > y+height) testY = y+height;

        float distX = circle.x-testX;
        float distY = circle.y-testY;
        float distance = sqrt((distX * distX) + (distY * distY));

        return distance <= circle.radius;
    }
}

class CollisionShape {
public:
    virtual bool intersects(CollisionShape &shape) = 0;
};


class PhysicsShape {
public:
    enum Type {
        RECTANGLE,
        CIRCLE
    };
    PhysicsShape() {}

    struct Circle {
        sf::Vector2f center;
        float radius;
    };
    union {
        sf::FloatRect rectangle;
        Circle circle;
    };
    Type type = RECTANGLE;
};

class PhysicsComponent {
public:
    Node &owner;
    PhysicsShape shape;
    PhysicsComponent(Node &owner): owner(owner) {

    }
    ~PhysicsComponent() {}

};
class Physics: public Collection<PhysicsComponent> {
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
        objects.push_back(PhysicsComponent(owner));
        return objects.size()-1;
    }
};

int main() {
    Physics physics;
    Node node;
    size_t pidx = physics.createObject(node);
    PhysicsComponent &physicsComponent = physics.getObject(pidx);
    physicsComponent.shape.type = PhysicsShape::RECTANGLE;
    physicsComponent.shape.rectangle.height = 100.f;
    physicsComponent.shape.rectangle.width = 20.f;

    GameWindow window(sf::VideoMode(640, 480),sf::String("HelloWorld"));
    
    window.addDrawable(std::shared_ptr<sf::Drawable>(new sf::CircleShape(100.f)));
    sf::Clock deltaClock;
    while (window.isOpen()) {
        float delta = deltaClock.restart().asSeconds();
        
        window.process(delta);
    }

    return EXIT_SUCCESS;
}
