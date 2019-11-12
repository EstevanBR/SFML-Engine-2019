#ifndef TEXTUREMANAGER_HPP
#define TEXTUREMANAGER_HPP

#include <map>
#include <string>
#include <memory>
#include <SFML/Graphics.hpp>

class TextureManager {
    static std::map<std::string, std::shared_ptr<sf::Texture> > _textures;
    static bool _loadTexture(const std::string fileName);
    static bool _textureLoaded(const std::string fileName);
public:
    static std::weak_ptr<sf::Texture> getTexture(const std::string fileName);
};

#endif
