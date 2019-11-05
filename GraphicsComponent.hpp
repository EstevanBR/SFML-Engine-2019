#ifndef GRAPHICS_COMPONENT_HPP
#define GRAPHICS_COMPONENT_HPP

#include "Component.hpp"

class Graphics;

template<class Owner>
class GraphicsComponent: public Component {
    friend class Graphics;
protected:
    GraphicsComponent(Engine &engine, Owner &owner): Component(engine) {
        
    }
};

#endif