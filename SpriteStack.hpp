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

    SpriteStack(std::string texturePath, sf::Vector3i sprite3DSize) {
        position = sf::Vector2f(30,64);
        
        this->sprite3DSize = sprite3DSize;
        if (texture.loadFromFile(texturePath)) {
            
        }
    }

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override {
        sf::Sprite sprite;
        sprite.setOrigin(sf::Vector2f(sprite3DSize.x / 2, sprite3DSize.y / 2));
        sprite.setPosition(position);
        sprite.setTexture(texture);
        for (int i = 0; i < sprite3DSize.z; i++) {
            sf::IntRect rect = sf::IntRect(sf::Vector2i(sprite3DSize.x * i, 0), sf::Vector2i(sprite3DSize.x, sprite3DSize.y));
            sprite.setTextureRect(rect);
            sprite.move(sf::Vector2f(0, -0.707f));
            sprite.setRotation(angle);
            target.draw(sprite, states);
        }
    }
    ~SpriteStack() {
        std::cout << "SpriteStack::~SpriteStack" << std::endl;
    }
};

#endif