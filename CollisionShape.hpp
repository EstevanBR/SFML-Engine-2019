#ifndef COLLISION_SHAPE_HPP
#define COLLISION_SHAPE_HPP

#include <cstdint>

class CollisionShape {
private:
    friend class Physics;
    uint16_t layers = 0;
public:
    void setLayers(uint16_t v);
    void setLayer(uint8_t layer, bool flag);
    uint16_t getLayers() const;
};

#endif