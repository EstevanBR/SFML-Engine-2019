#ifndef GAME_HPP
#define GAME_HPP

#include <memory>
#include <iostream>

#include <SFML/Graphics.hpp>

class Physics;
class Graphics;
class Input;
class Tree;

class Game {
protected:
    virtual void initialized(sf::RenderWindow &window, Tree &tree, Physics &physics, Graphics &graphics, Input &input) = 0;
public:
    int main(sf::VideoMode mode, const sf::String& title, sf::Uint32 style = sf::Style::Default, const sf::ContextSettings& settings = sf::ContextSettings());
};

#endif