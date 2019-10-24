#ifndef NODE_2D_HPP
#define NODE_2D_HPP

#include <SFML/Graphics.hpp>
#include "Node.hpp"
class Node;

class Node2D: public Node {
public:
    sf::Transform transform;
    void process(float delta) override;

};

#endif