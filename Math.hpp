#ifndef MATH_HPP
#define MATH_HPP

#include <cmath>
#include <SFML/System.hpp>

namespace math {
    extern const float TAU;
    extern const float PI;
    extern const float SQRT2;
    extern const float SQDAG;

    sf::Vector2f normalized(sf::Vector2f vector);
    float degreesToRadians(float angleInDegrees);
    sf::Vector2f rotateAroundOrigin(float radians, sf::Vector2f point);
}

#endif // MATH_HPP
