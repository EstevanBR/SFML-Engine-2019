#ifndef GAMEWINDOW_HPP
#define GAMEWINDOW_HPP

#include <memory>
#include <SFML/Graphics.hpp>
#include "Node.hpp"


class EventHandler {
public:
    virtual void handleEvent(sf::Event &event) = 0;
};

class GameWindow: public Node, public sf::RenderWindow {
public:
    GameWindow(sf::VideoMode mode, const sf::String &title, sf::Uint32 style=sf::Style::Default, const sf::ContextSettings &settings=sf::ContextSettings());
    void process(float delta) override;
    void addDrawable(std::shared_ptr<sf::Drawable> drawable);
protected:
    sf::View view;
    void onResize() override;
    std::vector<std::shared_ptr<EventHandler>> eventHandlers;
    void addEventHandler(EventHandler *handler);
    std::vector<std::shared_ptr<sf::Drawable>> drawables; 
};

#endif
