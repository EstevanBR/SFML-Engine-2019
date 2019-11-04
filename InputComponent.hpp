#ifndef INPUT_COMPONENT_HPP
#define INPUT_COMPONENT_HPP

#include "Component.hpp"
#include "Engine.hpp"

class Input;

template<class Owner>
class InputComponent: public Component {
    friend class Input;
protected:
    InputComponent(Engine &engine, Owner &owner):Component(engine) {}
};

#endif