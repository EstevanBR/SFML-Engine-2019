#ifndef MATH_HPP
#define MATH_HPP

#include <cmath>
#include <SFML/System.hpp>

namespace math {
    extern const float tau;
    extern const float pi;
    extern const float sqrt2;

    sf::Vector2f normalized(sf::Vector2f vector);
    float degreesToRadians(float angleInDegrees);
    float radiansToDegrees(float angleInRadians);
    sf::Vector2f rotateAroundOrigin(float radians, sf::Vector2f point);
    float dot(sf::Vector2f a, sf::Vector2f b);
    float angleTo(sf::Vector2f from, sf::Vector2f to);
}

#endif
