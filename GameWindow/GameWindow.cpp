#include "GameWindow.hpp"
#include <iostream>

GameWindow::GameWindow(
    sf::VideoMode mode,
    const sf::String &title,
    sf::Uint32 style,
    const sf::ContextSettings &settings): sf::RenderWindow(mode, title, style, settings) {
    
}

void GameWindow::onResize() {
    std::cout << "onResize" << std::endl;
}