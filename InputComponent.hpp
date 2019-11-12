#ifndef INPUT_COMPONENT_HPP
#define INPUT_COMPONENT_HPP

#include "Component.hpp"
#include "Engine.hpp"

class Input;

template<class Owner>
class InputComponent: public Component {
    friend class Input;
protected:
    InputComponent(Tree &tree, Owner &owner):Component(tree) {}
};

#endif