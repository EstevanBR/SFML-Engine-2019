#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include <SFML/Graphics.hpp>
#include "Collection.hpp"

class Graphics:public Collection<sf::Drawable> {
private:
	sf::RenderWindow &window;
	friend class Game;
	void test() {}
public:
	Graphics(sf::RenderWindow &window);
	void draw();
};

#endif