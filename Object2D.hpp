#ifndef NODE_2D_HPP
#define NODE_2D_HPP

#include <SFML/Graphics.hpp>

class Object2D {
public:
    sf::Transform transform;
    sf::Vector2f position;
};

#endif