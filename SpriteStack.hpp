#ifndef SPRITE_STACK_HPP
#define SPRITE_STACK_HPP

#include <cstdint>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "Node2D.hpp"

//class Node2D;

class SpriteStack: public Node2D, public sf::Drawable {
public:
    float angle = 0.f;
    sf::Texture texture;
    sf::Vector3i sprite3DSize;

    SpriteStack(std::string texturePath, sf::Vector3i sprite3DSize);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    ~SpriteStack();
};

#endif