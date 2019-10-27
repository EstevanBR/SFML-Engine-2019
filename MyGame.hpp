#ifndef MY_GAME_HPP
#define MY_GAME_HPP

#include <SFML/Graphics.hpp>
#include "Game.hpp"

class MyStack;

class MyGame: public Game {
public:
	sf::View view;
	std::shared_ptr<MyStack> myStack;
	void initialized(sf::RenderWindow &window, Tree &tree, Physics &physics, Graphics &graphics, Input &input) override;
	~MyGame();
};

#endif