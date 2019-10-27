#ifndef ANIMATED_SPRITE_HPP
#define ANIMATED_SPRITE_HPP

#include <vector>
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "Node.hpp"

class AnimateSprite: public sf::Drawable, public Node {
    void process(float delta) override {
        frame += delta * fps;
        if (frame >= fps) {
            frame = 0.f;
            std::cout << "reached elapsed time" << std::endl;
            
            sprite.setTexture(texture);
            sprite.setTextureRect(frames[frame]); 
        }
    }
public:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Clock deltaClock;

    float fps = 1;
    float frame = 0;
    std::vector<sf::IntRect> frames;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override {
       
    }
};

#endif
