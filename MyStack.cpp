#include "MyStack.hpp"

#include <memory>
#include <cmath>
#include "Tree.hpp"
#include "Graphics.hpp"
#include "Input.hpp"

std::string name = "MyStack";
MyStack::MyStack(Tree &tree, Graphics &graphics, Input &input):SpriteStack("icon.png", sf::Vector3i(16, 16, 16)) {
    tree.addObject(std::shared_ptr<Node>(this));
    graphics.Collection<sf::Drawable>::addObject(std::shared_ptr<sf::Drawable>(this));
    input.MessageDispatcher<UserInput>::addObject(std::shared_ptr<MessageHandler<UserInput>>(this));
}

void MyStack::process(float delta) {
    _velocity += _inputVector * 15.f * delta;
    _velocity.x *= _friction.x;
    _velocity.y *= _friction.y;

    position.x += _velocity.x;
    position.y += _velocity.y;

    _angle += delta * 180.f;
}

void MyStack::handleMessage(Message<UserInput> message) {
    _inputVector.x = 0.f;
    _inputVector.y = 0.f;

    _inputVector.x += (message.data.left) ? -1.f : 0.f;
    _inputVector.x += (message.data.right) ? 1.f : 0.f;
    _inputVector.y += (message.data.up) ? -1.f : 0.f;
    _inputVector.y += (message.data.down) ? 1.f : 0.f;

    if (_inputVector.x > 0.f || _inputVector.y > 0.f) {
        auto s = sqrtf(powf(_inputVector.x, 2.f) + powf(_inputVector.y, 2.f));
        _inputVector.x /= s;
        _inputVector.y /= s;
    }    
}