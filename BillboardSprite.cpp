#include "BillboardSprite.hpp"
#include "TextureManager.hpp"

BillboardSprite::BillboardSprite(std::string texturePath) {
    _texturePath = texturePath;
}

void BillboardSprite::process(float delta) {

}

void BillboardSprite::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    sf::Sprite sprite;
    sprite.setTexture(*TextureManager::getTexture(_texturePath).lock());
    sprite.setRotation(-target.getView().getRotation());
    target.draw(sprite, states);
}

BillboardSprite::~BillboardSprite() {

}