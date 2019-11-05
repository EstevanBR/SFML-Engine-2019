#include "Math.hpp"
#include <cmath>

namespace math {
    const float PI = 3.14159265359f;
    const float TAU = 6.28318530718f;
    const float SQRT2 = 1.41421356237f;
    const float SQDAG = 0.70710678118f;

    sf::Vector2f normalized(sf::Vector2f vector) {
        if (fabs(vector.x) > 0.f || fabs(vector.y) > 0.f) {
            auto s = sqrtf(powf(vector.x, 2.f) + powf(vector.y, 2.f));
            vector.x /= s;
            vector.y /= s;
            
            return vector;
        } else {
            return sf::Vector2f(0,0);
        }
    }

    float angleTo(sf::Vector2f from, sf::Vector2f to) {
        return atan2f(to.y - to.x, from.y - from.x);
    }

    float degreesToRadians(float angleInDegrees) {
        return TAU * (-angleInDegrees / 360.f);
    }

    float radiansToDegrees(float angleInRadians) {
        return angleInRadians * 180.f / PI;
    }

    sf::Vector2f rotateAroundOrigin(float radians, sf::Vector2f point) {
        
        auto rotatedPoint = sf::Vector2f(0,0);

        rotatedPoint.x = (point.x * cosf(radians)) - (point.y * sinf(radians));
        rotatedPoint.y = (point.y * cosf(radians)) + (point.x * sinf(radians));

        return rotatedPoint;
    }

    float dot(sf::Vector2f a, sf::Vector2f b) {
        return a.x * b.x + a.y * b.y;
    }
}
