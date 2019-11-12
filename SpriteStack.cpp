#include "SpriteStack.hpp"
#include <cmath>
#include <cstdint>
#include <iostream>
#include "Math.hpp"

SpriteStack::SpriteStack(std::string texturePath, sf::Vector3i sprite3DSize) {
    _sprite3DSize = sprite3DSize;
    _texturePath = texturePath;
    TextureManager::getTexture(_texturePath);
}

void SpriteStack::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    sf::Sprite sprite;

    auto texture = TextureManager::getTexture(_texturePath);
    if (!texture.expired()) {
        sprite.setOrigin(sf::Vector2f(_sprite3DSize.x / 2, -_sprite3DSize.y / 2));
        sprite.setPosition(position);
        sprite.setTexture(*texture.lock());
        for (int i = 0; i < _sprite3DSize.z; i++) {
            sf::IntRect rect = sf::IntRect(sf::Vector2i(_sprite3DSize.x * i, 0), sf::Vector2i(_sprite3DSize.x, _sprite3DSize.y));
            sprite.setTextureRect(rect);

            auto p = sf::Vector2f(0, -math::SQDAG);

            auto radians = math::degreesToRadians(-target.getView().getRotation());
            sprite.move(math::rotateAroundOrigin(radians, p));

            target.draw(sprite, states);
        }
    }
    
}
SpriteStack::~SpriteStack() {
    
    std::cout << "SpriteStack::~SpriteStack" << std::endl;
}
