#ifndef COLLISION_SHAPE_HPP
#define COLLISION_SHAPE_HPP

class CollisionShape {
public:
    virtual bool intersects(const CollisionShape &shape) const {return false;}
    virtual ~CollisionShape() {};
};

//
#endif