#ifndef INPUT_HPP
#define INPUT_HPP

#include <SFML/Graphics.hpp>
#include "Message.hpp"
#include "Node.hpp"

struct UserInputMap {
    sf::Keyboard::Key up = sf::Keyboard::W;
    sf::Keyboard::Key down = sf::Keyboard::S;
    sf::Keyboard::Key left = sf::Keyboard::A;
    sf::Keyboard::Key right = sf::Keyboard::D;
    sf::Keyboard::Key a = sf::Keyboard::K;
    sf::Keyboard::Key b = sf::Keyboard::J;
    sf::Keyboard::Key start = sf::Keyboard::Enter;
};

struct UserInput {
    bool up = false;
    bool down = false;
    bool left = false;
    bool right = false;
    bool a = false;
    bool b = false;
    bool start = false;
};

class Input: public Node, public MessageDispatcher<UserInput>  {
private:
    friend class Game;
    Input(sf::RenderWindow &window);
    
    UserInputMap inputMap;
    UserInput userInput;
    
    sf::RenderWindow &window;
    void process(float delta) override;

    void handlePress(bool &userInputState);
    void handleRelease(bool &userInputState);
};

#endif