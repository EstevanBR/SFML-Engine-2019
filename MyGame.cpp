#include "MyGame.hpp"

#include <SFML/Graphics.hpp>
#include "MyStack.hpp"


void MyGame::initialized(
    sf::RenderWindow &window,
    Tree &tree,
    Physics &physics,
    Graphics &graphics,
    Input &input) {
    
    std::cout << "MyGame::initialized" << std::endl;

    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(75.f);
    window.setKeyRepeatEnabled(false);

    view.setSize(window.getSize().x, window.getSize().y);

    myStack = std::shared_ptr<MyStack>(new MyStack(tree, graphics));
}

MyGame::~MyGame() {
    myStack.reset();
    std::cout << "MyGame::~MyGame" << std::endl;
}
