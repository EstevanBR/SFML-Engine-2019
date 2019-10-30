#include <iostream>
#include "Input.hpp"
#include "InputComponent.hpp"


Input::Input(sf::RenderWindow &window): _window(window) {

}

void Input::handlePress(bool &userInputState) {
    if (userInputState == false) {
        userInputState = true;
    }
}
void Input::handleRelease(bool &userInputState) {
    userInputState = false;
}
void Input::process(float delta) {
    sf::Event event;

    while(_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed or (event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::Escape)) {
            std::cout << "Goodbye!" << std::endl;
            _window.close();
        }
        if (event.type == sf::Event::EventType::KeyPressed) {
            auto code = event.key.code;
            
            if (code == inputMap.up)    handlePress(_userInput.up);
            if (code == inputMap.left)  handlePress(_userInput.left);
            if (code == inputMap.down)  handlePress(_userInput.down);
            if (code == inputMap.right) handlePress(_userInput.right);
            if (code == inputMap.a)     handlePress(_userInput.a);
            if (code == inputMap.b)     handlePress(_userInput.b);
            if (code == inputMap.start) handlePress(_userInput.start);

        } else if (event.type == sf::Event::EventType::KeyReleased) {
            auto code = event.key.code;

            if (code == inputMap.up)    handleRelease(_userInput.up);
            if (code == inputMap.left)  handleRelease(_userInput.left);
            if (code == inputMap.down)  handleRelease(_userInput.down);
            if (code == inputMap.right) handleRelease(_userInput.right);
            if (code == inputMap.a)     handleRelease(_userInput.a);
            if (code == inputMap.b)     handleRelease(_userInput.b);
            if (code == inputMap.start) handleRelease(_userInput.start);
        }
    }
    // for (auto ic: objects) {
    //     ic->handleInput(userInput);
    // }
}
