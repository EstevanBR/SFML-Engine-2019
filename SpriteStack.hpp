#ifndef SPRITE_STACK_HPP
#define SPRITE_STACK_HPP

#include <SFML/Graphics.hpp>
#include "TextureManager.hpp"

class SpriteStack: public sf::Drawable, public sf::Transformable {
    friend class Game;
    sf::Vector3i _sprite3DSize;
    std::string _texturePath;
public:
    SpriteStack(std::string texturePath, sf::Vector3i sprite3DSize);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    ~SpriteStack();
};

#endif