#include "GameWindow.hpp"
#include <iostream>

GameWindow::GameWindow(
    sf::VideoMode mode,
    const sf::String &title,
    sf::Uint32 style,
    const sf::ContextSettings &settings): sf::RenderWindow(mode, title, style, settings) {
    
    view.setSize(sf::Vector2f(getSize()));
    view.setCenter(sf::Vector2f(0.0, 0.0));
}

void GameWindow::onResize() {
    view.setSize(sf::Vector2f(getSize()));
}

