#include "Component.hpp"
#include "Engine.hpp"
#include "Tree.hpp"

Component::Component(Engine &engine): engine(engine) {
    engine.tree.addObject<Component>(std::shared_ptr<Component>(this));
}