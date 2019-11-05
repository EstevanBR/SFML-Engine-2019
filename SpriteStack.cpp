#include "SpriteStack.hpp"
#include <cmath>

#define TAU 6.28318530718f

SpriteStack::SpriteStack(std::string texturePath, sf::Vector3i sprite3DSize) {
    _sprite3DSize = sprite3DSize;
    if (_texture.loadFromFile(texturePath)) {
        
    } else {

    }
}

void SpriteStack::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    sf::Sprite sprite;


    sprite.setOrigin(sf::Vector2f(_sprite3DSize.x / 2, -_sprite3DSize.y / 2));
    sprite.setPosition(position);
    sprite.setTexture(_texture);
    for (int i = 0; i < _sprite3DSize.z; i++) {
        sf::IntRect rect = sf::IntRect(sf::Vector2i(_sprite3DSize.x * i, 0), sf::Vector2i(_sprite3DSize.x, _sprite3DSize.y));
        sprite.setTextureRect(rect);

        auto p = sf::Vector2f(0, -0.7071067811865476f);

        auto newP = sf::Vector2f();

        auto degrees = TAU * (-angle / 360.f);

        newP.x = (p.x * cosf(degrees)) - (p.y * sinf(degrees));
        newP.y = (p.y * cosf(degrees)) + (p.x * sinf(degrees));

        sprite.move(newP);

        target.draw(sprite, states);
    }
}
SpriteStack::~SpriteStack() {
    
    std::cout << "SpriteStack::~SpriteStack" << std::endl;
}
