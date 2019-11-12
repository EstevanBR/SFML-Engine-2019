#include "BillboardSprite.hpp"
#include "TextureManager.hpp"

BillboardSprite::BillboardSprite(std::string texturePath) {
    _texturePath = texturePath;
    //sf::Vector2f(windowSize.x / 2,windowSize.y / 2)
}

void BillboardSprite::process(float delta) {

}

void BillboardSprite::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    sf::Sprite sprite;
    sprite.setTexture(*TextureManager::getTexture(_texturePath).lock());
    
    target.draw(sprite, states);
}

BillboardSprite::~BillboardSprite() {

}