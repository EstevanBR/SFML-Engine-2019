#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <SFML/System.hpp>

template <class T>
class Circle: public sf::Vector2<T> {
public:
    T radius;
    Circle(sf::Vector2<T> center, T radius): sf::Vector2<T>(center) {
        radius = radius;
    }
    Circle(T x = 0, T y = 0, T radius = 0): sf::Vector2<T>(x, y) {
        radius = radius;
    }
};

typedef Circle<float> FloatCircle;

#endif