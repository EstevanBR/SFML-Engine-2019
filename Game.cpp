#include "Game.hpp"

#include "GameWindow.hpp"
#include "Physics.hpp"
#include "Graphics.hpp"
#include "Input.hpp"

int Game::main() {
    GameWindow window(sf::VideoMode(640, 480),sf::String("HelloWorld"));

	Physics physics;
	Graphics graphics(window);
	Input input(window);

	graphics.test();

	sf::Clock deltaClock;
	
	while (window.isOpen()) {
		float delta = deltaClock.restart().asSeconds();

		input.process(delta);
		physics.process(delta);
		graphics.draw();
	}

	return EXIT_SUCCESS;
}