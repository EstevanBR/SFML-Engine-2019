#include "Game.hpp"

#include "Physics.hpp"
#include "Graphics.hpp"
#include "Input.hpp"

Game::Game(sf::RenderWindow &window):window(window) {
	physics = std::unique_ptr<Physics>(new Physics);
	graphics = std::unique_ptr<Graphics>(new Graphics(window));
	input = std::unique_ptr<Input>(new Input(window));
}

int Game::main() {
	sf::Clock deltaClock;
	
	while (window.isOpen()) {
		float delta = deltaClock.restart().asSeconds();

		input->process(delta);
		physics->process(delta);
		graphics->draw();
	}

	return EXIT_SUCCESS;
}

Game::~Game() {
	std::cout << "Game::~Game" << std::endl;
}