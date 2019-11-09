#ifndef SPRITE_STACK_HPP
#define SPRITE_STACK_HPP

#include <SFML/Graphics.hpp>
#include "Object2D.hpp"
#include "TextureManager.hpp"

class SpriteStack: public sf::Drawable, public Object2D {
private:
    friend class Game;
    sf::Vector3i _sprite3DSize;
    std::string _texturePath;
protected:
public:
    float angle = 0.f;
    SpriteStack(std::string texturePath, sf::Vector3i sprite3DSize);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    ~SpriteStack();
};

#endif