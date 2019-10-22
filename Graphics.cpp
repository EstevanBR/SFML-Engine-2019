#include "Graphics.hpp"

Graphics::Graphics(sf::RenderWindow &window):window(window) {
    
}

void Graphics::draw() {
    window.clear();
    for (auto d: objects) {
        window.draw(*d.get());
    }
    window.display();
}
