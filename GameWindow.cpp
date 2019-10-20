#include "GameWindow.hpp"
#include <iostream>

GameWindow::GameWindow(
    sf::VideoMode mode,
    const sf::String &title,
    sf::Uint32 style,
    const sf::ContextSettings &settings): sf::RenderWindow(mode, title, style, settings) {
    
    std::cout << "GameWindow::GameWindow()" << std::endl;
    view.setSize(sf::Vector2f(640.f, 480.f));
    view.setCenter(sf::Vector2f(0.0, 10.0));
    setView(view);
}

void GameWindow::onResize() {
    std::cout << "GameWindow::onResize()" << std::endl;
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
