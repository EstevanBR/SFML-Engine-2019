#include "Game.hpp"

#include "Physics.hpp"
#include "Graphics.hpp"
#include "Input.hpp"
#include "Tree.hpp"

int Game::main(
		sf::VideoMode mode,
		const sf::String& title,
		sf::Uint32 style,
		const sf::ContextSettings& settings) {
	sf::RenderWindow window(mode, title, style, settings);
	window.setPosition(sf::Vector2i(1920/2 - window.getSize().x / 2, 1080/2 - window.getSize().y / 2));
	
	sf::View view = sf::View(sf::FloatRect(0,0,1920 * 0.25, 1080 * 0.25));
	window.setView(view);

	auto tree = std::unique_ptr<Tree>(new Tree);
	auto physics = std::unique_ptr<Physics>(new Physics);
	auto graphics = std::unique_ptr<Graphics>(new Graphics(window));
	auto input = std::unique_ptr<Input>(new Input(window));

	initialized(window, *tree, *physics, *graphics, *input);

	sf::Clock deltaClock;
	deltaClock.restart();
	float delta = 0.f;
	while (window.isOpen()) {
		delta = deltaClock.restart().asSeconds();
		
		input->process(delta);
		tree->process(delta);
		physics->process(delta);
		graphics->process(delta);
	}

	tree.release();
	physics.release();
	graphics.release();
	input.release();

	return EXIT_SUCCESS;
}
