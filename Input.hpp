#ifndef INPUT_HPP
#define INPUT_HPP

#include <SFML/Graphics.hpp>
#include "Message.hpp"
#include "Node.hpp"

// enum UserInputType {
//     NONE = 0,
//     UP = 1,
//     DOWN = 2,
//     LEFT = 4,
//     RIGHT = 8,
//     A = 16,
//     B = 32,
//     START = 64
// };
struct UserInputMap {
    sf::Keyboard::Key up = sf::Keyboard::W;
    sf::Keyboard::Key down = sf::Keyboard::S;
    sf::Keyboard::Key left = sf::Keyboard::A;
    sf::Keyboard::Key right = sf::Keyboard::D;
    sf::Keyboard::Key a = sf::Keyboard::K;
    sf::Keyboard::Key b = sf::Keyboard::J;
    sf::Keyboard::Key start = sf::Keyboard::Enter;
};

// enum UserInputState {
//     NOT_PRESSED = 0,
//     // JUST_RELEASED,
//     PRESSED,
//     //JUST_PRESSED
// };
struct UserInput {
    bool up = false;
    bool down = false;
    bool left = false;
    bool right = false;
    bool a = false;
    bool b = false;
    bool start = false;
};

class Input: public Node, public MessageDispatcher  {
private:
    friend class Game;

    UserInputMap inputMap;
    UserInput userInput;
    
    sf::RenderWindow &window;
    void process(float delta) override;

    void handlePress(bool &userInputState);
    void handleRelease(bool &userInputState);
    void log();
    void logState(std::string buttonName, bool const& userInputState);
public:
    
    Input(sf::RenderWindow &window);
    
};

#endif