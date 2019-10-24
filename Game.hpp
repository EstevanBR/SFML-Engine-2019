#ifndef GAME_HPP
#define GAME_HPP

#include <memory>
#include <iostream>

namespace sf {
    class RenderWindow;
}

class Physics;
class Graphics;
class Input;
class Tree;

class Game {
protected:
	sf::RenderWindow &window;
    std::unique_ptr<Tree> tree;
    std::unique_ptr<Physics> physics;
    std::unique_ptr<Graphics> graphics;
    std::unique_ptr<Input> input;
    //virtual void initialized(sf::RenderWindow &window, Tree &tree, Physics &physics, Graphics &graphics, Input &input) {};
public:
    Game(sf::RenderWindow &window);
    ~Game();
    int main();
};

#endif