#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include <SFML/Graphics.hpp>
#include "Collection.hpp"
#include "Node.hpp"

class Graphics: private Node, public Collection<sf::Drawable> {
private:
	sf::RenderWindow &window;
	friend class Game;
	Graphics(sf::RenderWindow &window);
	void process(float delta) override;
};

#endif