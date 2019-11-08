#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <SFML/Graphics.hpp>

class Physics;
class Input;
class Tree;
class Graphics;
class Camera;

struct Engine {
    Graphics &graphics;
    Input &input;
    Physics &physics;
    Tree &tree;
    sf::RenderWindow &window;
    Camera &camera;
    Engine(Graphics &graphics, Input &input, Physics &physics, Tree &tree, sf::RenderWindow &window, Camera &camera);
};

#endif