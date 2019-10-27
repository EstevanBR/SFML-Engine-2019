#ifndef MY_STACK_HPP
#define MY_STACK_HPP

#include <memory>
#include "SpriteStack.hpp"
#include "Message.hpp"
#include "Input.hpp"


class Tree;
class Graphics;
class Input;

class MyStack: public SpriteStack, public MessageHandler {
public:
	std::string name = "MyStack";
	MyStack(Tree &tree, Graphics &graphics, Input &input);
	void process(float delta) override;
	template <class T>
	void handleMessage(Message<T> message) {
		MessageHandler::handleMessage(message);
	};
};



#endif