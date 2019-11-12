#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <SFML/Graphics.hpp>

class Camera: public sf::View {
public:
    Camera(sf::FloatRect floatRect): sf::View(floatRect) {

    }
};


#endif
