#include "MyStack.hpp"

#include "Tree.hpp"
#include "Graphics.hpp"

std::string name = "MyStack";
MyStack::MyStack(Tree &tree, Graphics &graphics):SpriteStack("icon.png", sf::Vector3i(16, 16, 16)) {
    tree.addObject(std::shared_ptr<Node>(this));
    graphics.addObject(std::shared_ptr<sf::Drawable>(this));
}

void MyStack::process(float delta) {
    angle += delta * 360.f;
}