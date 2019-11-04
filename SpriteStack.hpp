#ifndef SPRITE_STACK_HPP
#define SPRITE_STACK_HPP

#include <cstdint>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "Object2D.hpp"

//class Node2D;

class SpriteStack: public sf::Drawable, public Object2D {
private:
    friend class Game;
    sf::Texture _texture;
    sf::Vector3i _sprite3DSize;
protected:
public:
    float angle = 0.f;
    SpriteStack(std::string texturePath, sf::Vector3i sprite3DSize);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    ~SpriteStack();
};

#endif