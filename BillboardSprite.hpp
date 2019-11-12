#ifndef BILLBOARDSPRITE_HPP
#define BILLBOARDSPRITE_HPP

#include <SFML/Graphics.hpp>


class BillboardSprite: public sf::Drawable, public sf::Transformable {
    friend class Game;
    std::string _texturePath;
    public:
    BillboardSprite(std::string texturePath);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    ~BillboardSprite();
};

#endif
