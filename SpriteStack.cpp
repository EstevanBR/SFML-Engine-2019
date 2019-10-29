#include "SpriteStack.hpp"

SpriteStack::SpriteStack(std::string texturePath, sf::Vector3i sprite3DSize) {
    position = sf::Vector2f(30,64);
    _sprite3DSize = sprite3DSize;
    if (_texture.loadFromFile(texturePath)) {
        
    } else {

    }
}

void SpriteStack::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    sf::Sprite sprite;


    sprite.setOrigin(sf::Vector2f(_sprite3DSize.x / 2, _sprite3DSize.y / 2));
    sprite.setPosition(position);
    sprite.setTexture(_texture);
    for (int i = 0; i < _sprite3DSize.z; i++) {
        sf::IntRect rect = sf::IntRect(sf::Vector2i(_sprite3DSize.x * i, 0), sf::Vector2i(_sprite3DSize.x, _sprite3DSize.y));
        sprite.setTextureRect(rect);
        sprite.move(sf::Vector2f(0, -0.707));
        sprite.setRotation(_angle);
        target.draw(sprite, states);
    }
}
SpriteStack::~SpriteStack() {
    
    std::cout << "SpriteStack::~SpriteStack" << std::endl;
}
