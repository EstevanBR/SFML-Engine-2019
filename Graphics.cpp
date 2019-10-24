#include <iostream>
#include "Graphics.hpp"

Graphics::Graphics(sf::RenderWindow &window):window(window) {
    
}

void Graphics::draw() {
    //std::cout << "Graphics::draw" << std::endl;
    window.clear(sf::Color::Black);
    for (auto d: objects) {
        
        window.draw(*d);
    }
    window.display();
}
