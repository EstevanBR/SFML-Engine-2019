#ifndef INPUT_COMPONENT_HPP
#define INPUT_COMPONENT_HPP

#include "Component.hpp"

class Input;

template<class Owner>
class InputComponent: public Component<Input, Owner> {
    friend class Input;
protected:
    InputComponent(Input &input, Owner &owner):Component<Input, Owner>(input, owner) {}
};

#endif