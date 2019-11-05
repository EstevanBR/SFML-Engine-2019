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
    float radiansToDegrees(float angleInRadians);
    sf::Vector2f rotateAroundOrigin(float radians, sf::Vector2f point);
    float dot(sf::Vector2f a, sf::Vector2f b);
    float angleTo(sf::Vector2f from, sf::Vector2f to);
}

#endif // MATH_HPP
