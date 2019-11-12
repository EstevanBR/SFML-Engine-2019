#ifndef GRAPHICS_COMPONENT_HPP
#define GRAPHICS_COMPONENT_HPP

#include "Component.hpp"

class Graphics;

template<class Owner>
class GraphicsComponent: public Component {
    friend class Graphics;
protected:
    const Graphics &graphics;
    GraphicsComponent(Graphics &graphics, Tree &tree, Owner &owner): Component(tree), graphics(graphics) {}
};

#endif