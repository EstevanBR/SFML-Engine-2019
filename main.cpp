#include <SFML/Graphics.hpp>
#include "Game.hpp"

#include "Physics.hpp"
#include "Graphics.hpp"
#include "Input.hpp"
#include "RectCollisionShape.hpp"

#include "SpriteStack.hpp"

auto s = SpriteStack("icon.png", sf::Vector3i(16, 16, 16));

class MyGame: public Game {
public:
	MyGame(sf::RenderWindow &window):Game::Game(window) {
		initialized(window, *physics, *graphics, *input);
	}
	void initialized(sf::RenderWindow &window, Physics &physics, Graphics &graphics, Input &input) {
		std::cout << "MyGame::initialized" << std::endl;
		// auto pc_idx = physics.createObject<RectCollisionShape>();
		// auto pc = physics.getObject<RectCollisionShape>(pc_idx);

		// auto rs_idx = graphics.createObject<sf::RectangleShape>();
		// auto rs = graphics.getObject<sf::RectangleShape>(rs_idx);

		// rs->setFillColor(sf::Color::Blue);
		// rs->setPosition(sf::Vector2f(10,10));
		// rs->setSize(sf::Vector2f(100,30));

		graphics.objects.push_back(std::shared_ptr<sf::Drawable>(static_cast<sf::Drawable *> (&s)));
	}
	~MyGame() {
		std::cout << "MyGame::~MyGame" << std::endl;
	}
};

int main() {
	sf::RenderWindow window(sf::VideoMode(640,480), "MyGame", sf::Style::Titlebar|sf::Style::Close);

	return MyGame(window).main();	
}
