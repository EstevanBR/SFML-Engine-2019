#include "Input.hpp"

Input::Input(sf::RenderWindow &window): window(window) {

}
void Input::process(float delta) {
    sf::Event event;
    while(window.pollEvent(event)) {
        if (event.type == sf::Event::Closed or (event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::Escape)) {
            std::cout << "Goodbye!" << std::endl;
            window.close();
        }

        auto message = Message<sf::Event>("event", event);
        dispatchMessage(message);
    }
}