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

void GameWindow::addEventHandler(EventHandler *handler) {
    eventHandlers.push_back(std::shared_ptr<EventHandler>(handler));
}

void GameWindow::addDrawable(std::shared_ptr<sf::Drawable> drawable) {
    drawables.push_back(drawable);
}

void GameWindow::process(float delta) {
    // input
    sf::Event event;
    for(;pollEvent(event);) {
        if (event.type == sf::Event::Closed or (event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::Escape)) {
            std::cout << "Goodbye!" << std::endl;
            exit(0);
            return;
        }
        for (auto handler: eventHandlers) {
            assert(handler.get() != nullptr);
            handler->handleEvent(event);
        }
        auto message = Message<sf::Event>("event", event);
        dispatchMessage(message);
    }
    // objects
    for (auto node: children) {
        node->process(delta);
    }
    // physics

    clear();
    //
    view.rotate(90.f * delta);
    setView(view);
    
    for (auto d: drawables) {
        draw(*d.get());
    }
    display();
}
