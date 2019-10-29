#ifndef PROCESSOR_HPP
#define PROCESSOR_HPP

#include <memory>
#include "Collection.hpp"

class Parent;
class Child;
class Processor;

class Processor {
    void process(float)
    virtual void process(float delta) = 0;
};

class Parent: private Collection<Child> {};

class Child {
    std::weak_ptr<Parent> parent;
};

#endif