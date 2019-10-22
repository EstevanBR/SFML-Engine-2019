#ifndef INPUT_HPP
#define INPUT_HPP

#include <SFML/Graphics.hpp>
#include "Message.hpp"

class Input: public MessageDispatcher  {
private:
    friend class Game;
    sf::RenderWindow &window;
    void process(float delta);
public:
    
    Input(sf::RenderWindow &window);
    
};

#endif