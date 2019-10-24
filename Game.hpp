#ifndef GAME_HPP
#define GAME_HPP

#include <memory>
namespace sf {
    class RenderWindow;
}

class Physics;
class Graphics;
class Input;

class Game {
protected:
	sf::RenderWindow &window;
    std::unique_ptr<Physics> physics;
    std::unique_ptr<Graphics> graphics;
    std::unique_ptr<Input> input;
    //virtual void initialized(sf::RenderWindow &window, Physics &physics, Graphics &graphics, Input &input) = 0;
public:
    Game(sf::RenderWindow &window);
    ~Game();
    int main();
};

#endif