#ifndef MY_STACK_HPP
#define MY_STACK_HPP

#include <memory>
#include "SpriteStack.hpp"
#include "Message.hpp"
#include "Input.hpp"
#include "PhysicsComponent.hpp"

class Tree;
class Graphics;
class Input;
class UserInput;

class MyStack: public SpriteStack, public MessageHandler<UserInput> {
private:
	std::shared_ptr<PhysicsComponent> physicsComponent;
	sf::Vector2f _inputVector;
	sf::Vector2f _velocity;
	sf::Vector2f _friction = sf::Vector2f(0.9f, 0.9f);

	std::string name = "MyStack";
	void handleMessage(Message<UserInput> message) override;
public:
	MyStack(Tree &tree, Graphics &graphics, Input &input);
	void process(float delta) override;
};

#endif