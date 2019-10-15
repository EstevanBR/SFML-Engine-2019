#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

#include "GameWindow/GameWindow.hpp"

int main() {
    GameWindow window(sf::VideoMode(640, 480),sf::String("HelloWorld"));
    sf::View view = sf::View(sf::Vector2f(0.0, 10.0), sf::Vector2f(640, 480));

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Red);

    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.setView(view);
        view.rotate(0.01);

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
