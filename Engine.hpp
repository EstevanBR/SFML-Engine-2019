#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <SFML/Graphics.hpp>
#include "Physics.hpp"
#include "Graphics.hpp"
#include "Input.hpp"
#include "Tree.hpp"

class Camera: public sf::View {
public:
    Camera(sf::FloatRect floatRect): sf::View(floatRect) {

    }
};

struct Engine {
    Graphics &graphics;
    Input &input;
    Physics &physics;
    Tree &tree;
    sf::RenderWindow &window;
    Camera &camera;
    Engine(Graphics &graphics, Input &input, Physics &physics, Tree &tree, sf::RenderWindow &window, Camera &camera):
        graphics(graphics), input(input), tree(tree), physics(physics), window(window), camera(camera) {

    }
};

#endif