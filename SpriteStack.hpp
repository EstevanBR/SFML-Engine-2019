#ifndef SPRITE_STACK_HPP
#define SPRITE_STACK_HPP

#include <cstdint>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "Node2D.hpp"

//class Node2D;

class SpriteStack: public Node2D, public sf::Drawable {
private:
    friend class Game;
    sf::Texture _texture;
    sf::Vector3i _sprite3DSize;
protected:
    float _angle = 0.f;
    SpriteStack(std::string texturePath, sf::Vector3i sprite3DSize);
public:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    ~SpriteStack();
};

#endif