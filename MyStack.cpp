#include "MyStack.hpp"

#include <memory>
#include "Tree.hpp"
#include "Graphics.hpp"
#include "Input.hpp"

std::string name = "MyStack";
MyStack::MyStack(Tree &tree, Graphics &graphics, Input &input):SpriteStack("icon.png", sf::Vector3i(16, 16, 16)) {
    tree.addObject(std::shared_ptr<Node>(this));
    graphics.addObject(std::shared_ptr<sf::Drawable>(this));
    input.MessageDispatcher::addObject(std::shared_ptr<MessageHandler>(this));
}

void MyStack::process(float delta) {
    angle += delta * 360.f;
}

// template<>
// void MyStack::handleMessage<UserInput const &>(Message<UserInput const &> message) {
// 	std::cout << "message" << std::endl;
// }