#ifndef GRAPHICS_COMPONENT_HPP
#define GRAPHICS_COMPONENT_HPP

#include <SFML/Graphics.hpp>

#include "Component.hpp"
#include "Collection.hpp"

class Node;
class Graphics;

class GraphicsComponent: public Component<Graphics> {};

#endif