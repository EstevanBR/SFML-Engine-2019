#ifndef MATH_HPP
#define MATH_HPP

#include <cmath>
#include <SFML/System.hpp>

template<typename T>
sf::Vector2<T> Normalize(sf::Vector2<T> vector) {
    if (fabs(vector.x) > 0.f || fabs(vector.y) > 0.f) {
        auto s = sqrtf(powf(vector.x, 2.f) + powf(vector.y, 2.f));
        vector.x /= s;
        vector.y /= s;
    } else {
        // vector was 0,0
        return sf::Vector2<T>(0,0);
    }
}

float RandomFloat(float a, float b) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}

#endif // MATH_HPP
