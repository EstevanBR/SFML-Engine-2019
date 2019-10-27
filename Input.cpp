#include <iostream>
#include "Input.hpp"

Input::Input(sf::RenderWindow &window): window(window) {
    
}
void Input::handlePress(bool &userInputState) {
    switch (userInputState) {
        case false:
            userInputState = true;
            break;
    }
}
void Input::handleRelease(bool &userInputState) {
    userInputState = false;
}
void Input::process(float delta) {
    sf::Event event;
    while(window.pollEvent(event)) {
        if (event.type == sf::Event::Closed or (event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::Escape)) {
            std::cout << "Goodbye!" << std::endl;
            window.close();
        }
        if (event.type == sf::Event::EventType::KeyPressed) {
            auto code = event.key.code;
            
            if (code == inputMap.up)    handlePress(userInput.up);
            if (code == inputMap.left)  handlePress(userInput.left);
            if (code == inputMap.down)  handlePress(userInput.down);
            if (code == inputMap.right) handlePress(userInput.right);
            if (code == inputMap.a)     handlePress(userInput.a);
            if (code == inputMap.b)     handlePress(userInput.b);
            if (code == inputMap.start) handlePress(userInput.start);

        } else if (event.type == sf::Event::EventType::KeyReleased) {
            auto code = event.key.code;

            if (code == inputMap.up)    handleRelease(userInput.up);
            if (code == inputMap.left)  handleRelease(userInput.left);
            if (code == inputMap.down)  handleRelease(userInput.down);
            if (code == inputMap.right) handleRelease(userInput.right);
            if (code == inputMap.a)     handleRelease(userInput.a);
            if (code == inputMap.b)     handleRelease(userInput.b);
            if (code == inputMap.start) handleRelease(userInput.start);
        }
        
        auto message = Message<UserInput const &>("user.input.event", userInput);
        dispatchMessage(message);
    }
    //log();
}

void Input::log() {
    logState("UP",    userInput.up);
    logState("DOWN",  userInput.down);
    logState("LEFT",  userInput.left);
    logState("RIGHT", userInput.right);
    logState("A",     userInput.a);
    logState("B",     userInput.b);
    logState("START", userInput.start);
}
void Input::logState(std::string buttonName, bool const& userInputState) {
    std::cout << buttonName << ": ";
    std::cout << ((userInputState == true) ? "PRESSED" : "");
    //std::cout << ((userInputState == JUST_PRESSED) ? "JUST_PRESSED" : "");
    std::cout << ((userInputState == false) ? "NOT_PRESSED" : "");
    //std::cout << ((userInputState == JUST_RELEASED) ? "JUST_RELEASED" : "");
    std::cout << std::endl;
    std::cout << std::endl;
}