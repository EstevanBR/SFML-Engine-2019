#include <SFML/Graphics.hpp>
#include "Game.hpp"

#include "Tree.hpp"
#include "Physics.hpp"
#include "Graphics.hpp"
#include "Input.hpp"
#include "RectCollisionShape.hpp"

#include "SpriteStack.hpp"

class MyStack: public SpriteStack {
public:
	MyStack():SpriteStack("icon.png", sf::Vector3i(16, 16, 16)) {

	}

	void process(float delta) override {
		angle += delta * 90.f;
	}
};

class MyGame: public Game {
public:
	sf::View view;
	
	MyGame(sf::RenderWindow &window):Game::Game(window) {
		window.setVerticalSyncEnabled(true);
		window.setFramerateLimit(100.f);
		
		view.setSize(window.getSize().x, window.getSize().y);
		initialized(window, *tree, *physics, *graphics, *input);
	}
	void initialized(sf::RenderWindow &window, Tree &tree, Physics &physics, Graphics &graphics, Input &input) {
		std::cout << "MyGame::initialized" << std::endl;

		std::shared_ptr<MyStack> s = std::shared_ptr<MyStack>(new MyStack);

		tree.objects.push_back(std::shared_ptr<Node>(s));
		graphics.objects.push_back(std::shared_ptr<sf::Drawable>(s));
	}
	~MyGame() {
		std::cout << "MyGame::~MyGame" << std::endl;
	}
};


int main() {
	sf::RenderWindow window(sf::VideoMode(640,480), "MyGame", sf::Style::Titlebar|sf::Style::Close);

	return MyGame(window).main();	
}
