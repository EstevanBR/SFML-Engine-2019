#ifndef COLLISION_SHAPE_HPP
#define COLLISION_SHAPE_HPP

#include <memory>
#include <cstdint>
#include <SFML/Graphics.hpp>
#include <vector>

class PhysicsComponent;

class CollisionShape {
private:
    friend class Physics;
    uint16_t layers = 0;
    size_t _id;
    PhysicsComponent &_physicsComponent;
public:
    const size_t &id = _id;
    CollisionShape(PhysicsComponent &physicsComponent);
    void setLayers(uint16_t v);
    void setLayer(uint8_t layer, bool flag);
    uint16_t getLayers() const;
    template<class T>
    bool belongsTo() {
        T *t = dynamic_cast<T *>(&_physicsComponent);
        return t != nullptr;
    }
};

#endif