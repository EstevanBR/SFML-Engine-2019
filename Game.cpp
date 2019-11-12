#include "Game.hpp"
#include "Engine.hpp"
#include "Tree.hpp"
#include "Physics.hpp"
#include "Camera.hpp"
#include "Graphics.hpp"
#include "Input.hpp"

int Game::main(
		sf::VideoMode mode,
		const sf::String& title,
		sf::Uint32 style,
		const sf::ContextSettings& settings) {
	sf::RenderWindow window(mode, title, style, settings);
	window.setPosition(sf::Vector2i(1920/2 - window.getSize().x / 2, 1080/2 - window.getSize().y / 2));
	
	Camera camera(sf::FloatRect(0,0,1920 * 0.25, 1080 * 0.25));
	auto tree = std::unique_ptr<Tree>(new Tree);
	auto physics = std::unique_ptr<Physics>(new Physics);
	auto graphics = std::unique_ptr<Graphics>(new Graphics(window));
	auto input = std::unique_ptr<Input>(new Input(window));

	Engine engine(*graphics, *input, *physics, *tree, window, camera);

	initialized(engine);

	sf::Clock deltaClock;
	deltaClock.restart();
	float delta = 0.f;
	while (window.isOpen()) {
		delta = deltaClock.restart().asSeconds();
		input->process(delta);
		tree->process(delta);
		physics->process(delta);
		
		camera.rotate(delta * 10.f);
		window.setView(camera);
		
		graphics->process(delta);
	}

	tree.release();
	physics.release();
	graphics.release();
	input.release();

	return EXIT_SUCCESS;
}
