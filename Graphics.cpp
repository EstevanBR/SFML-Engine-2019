#include <iostream>
#include "Graphics.hpp"

Graphics::Graphics(sf::RenderWindow &window):window(window) {
    
}

void Graphics::process(float delta) {
    window.clear(sf::Color::Black);
    for (auto d: Collection<sf::Drawable>::objects) {
        
        window.draw(*d);
    }
    window.display();
}
