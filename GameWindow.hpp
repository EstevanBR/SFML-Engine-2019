#ifndef GAMEWINDOW_HPP
#define GAMEWINDOW_HPP

//#include <memory>
#include <SFML/Graphics.hpp>
//#include "Node.hpp"

class GameWindow: public sf::RenderWindow {
public:
    GameWindow(sf::VideoMode mode, const sf::String &title, sf::Uint32 style=sf::Style::Default, const sf::ContextSettings &settings=sf::ContextSettings());
protected:
    sf::View view;
    void onResize() override;
};

#endif
