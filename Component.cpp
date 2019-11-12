#include "Component.hpp"
#include "Tree.hpp"

Component::Component(Tree &tree) {
    tree.addObject<Component>(std::shared_ptr<Component>(this));
}