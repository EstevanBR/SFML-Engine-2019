#ifndef SPRITE_STACK_HPP
#define SPRITE_STACK_HPP

#include <cstdint>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "Node2D.hpp"

//class Node2D;

class SpriteStack: public Node2D, public sf::Drawable {
public:
    //sf::Sprite sprite;
    sf::Texture texture;
    sf::Vector3i size;

    SpriteStack(std::string texturePath, sf::Vector3i size) {
        if (texture.loadFromFile(texturePath)) {
            size = size;    
        }
        

    }
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override {
        sf::Sprite sprite;
        
        for (int i = 0; i < size.z; i++) {
            std::cout << "DRAW?" << std::endl;
            sf::IntRect rect = sf::IntRect(sf::Vector2i(size.x * i, 0), sf::Vector2i(size.x, size.y));
            sprite.setTexture(texture);
            sprite.setTextureRect(rect);
            target.draw(sprite, states);
        }
    }
    ~SpriteStack() {

    }
};

#endif