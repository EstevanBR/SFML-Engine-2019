#ifndef BILLBOARDSPRITE_HPP
#define BILLBOARDSPRITE_HPP

#include <SFML/Graphics.hpp>
#include "Object2D.hpp"
#include "Node.hpp"


class BillboardSprite: public sf::Drawable, public Object2D, public Node {
    friend class Game;
    std::string _texturePath;
    public:
    BillboardSprite(std::string texturePath);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    ~BillboardSprite();
    void process(float delta);
};

#endif
