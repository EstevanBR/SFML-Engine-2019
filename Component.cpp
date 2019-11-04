#include "Component.hpp"
#include "Node.hpp"
#include "Engine.hpp"

Component::Component(Engine &engine): engine(engine) {
    engine.tree.addObject<Component>(std::shared_ptr<Component>(this));
}