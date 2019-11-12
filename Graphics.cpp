#include <iostream>
#include "Graphics.hpp"

Graphics::Graphics(sf::RenderWindow &window):
    _window(window) {
    
}

void Graphics::process(float delta) {
    _window.clear(sf::Color::Black);
    for (auto d: Collection<sf::Drawable>::objects) {
        
        _window.draw(*d);
    }
    _window.display();
}
