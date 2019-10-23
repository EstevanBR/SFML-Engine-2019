#ifndef GRAPHICS_COMPONENT_HPP
#define GRAPHICS_COMPONENT_HPP

#include <SFML/Graphics.hpp>

#include "Component.hpp"
#include "Collection.hpp"

class Node;

class GraphicsComponent: public Collection<sf::Drawable>, public Component {
private:
	friend class Graphics;
	GraphicsComponent(Node &owner);
};

#endif