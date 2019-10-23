#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>

class Physics;
class Graphics;
class Input;

class Game {
protected:
    std::unique_ptr<Physics> physics;
    std::unique_ptr<Graphics> graphics;
    std::unique_ptr<Input> input;
public:
    Game();
    ~Game();
    int main();
};

#endif