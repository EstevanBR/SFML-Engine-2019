#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <SFML/Graphics.hpp>
#include "Physics.hpp"
#include "Graphics.hpp"
#include "Input.hpp"
#include "Tree.hpp"

struct Engine {
    Graphics &graphics;
    Input &input;
    Physics &physics;
    Tree &tree;
    sf::RenderWindow &window;
    Engine(Graphics &graphics, Input &input, Physics &physics, Tree &tree, sf::RenderWindow &window):
        graphics(graphics), input(input), tree(tree), physics(physics), window(window) {

    }
};

#endif