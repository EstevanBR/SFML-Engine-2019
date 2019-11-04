#include "CollisionShape.hpp"
#include "PhysicsComponent.hpp"
CollisionShape::CollisionShape(PhysicsComponent &physicsComponent): _physicsComponent(physicsComponent) {
    static size_t count = 0;
    _id = count;
    count++;
}

void CollisionShape::setLayers(uint16_t v) {
    layers = v;
}
void CollisionShape::setLayer(uint8_t layer, bool flag) {
    layers |= (flag << layer) & 0xF;
}
uint16_t CollisionShape::getLayers() const {
    return layers;
}