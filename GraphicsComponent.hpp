#ifndef GRAPHICS_COMPONENT_HPP
#define GRAPHICS_COMPONENT_HPP

#include "Component.hpp"

class Graphics;

template<class Owner>
class GraphicsComponent: public Component<Graphics, Owner> {
    friend class Graphics;
    GraphicsComponent(Owner &owner):Component<Graphics, Owner>(owner) {}
};

#endif