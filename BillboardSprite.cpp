#include "BillboardSprite.hpp"
#include "TextureManager.hpp"

BillboardSprite::BillboardSprite(std::string texturePath) {
    _texturePath = texturePath;
}

void BillboardSprite::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    sf::Sprite sprite;
    sf::Texture &texture = *TextureManager::getTexture(_texturePath).lock();
    sprite.setPosition(getPosition());
    sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y);
    sprite.setTexture(texture);
    sprite.setRotation(target.getView().getRotation());
    target.draw(sprite, states);
}

BillboardSprite::~BillboardSprite() {

}