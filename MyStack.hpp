#ifndef MY_STACK_HPP
#define MY_STACK_HPP

#include <memory>
#include "SpriteStack.hpp"

class Tree;
class Graphics;

class MyStack: public SpriteStack {
public:
	std::string name = "MyStack";
	MyStack(Tree &tree, Graphics &graphics);
	void process(float delta) override;
};

#endif