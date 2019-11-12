#include "TextureManager.hpp"

std::map<std::string, std::shared_ptr<sf::Texture>> TextureManager::_textures;

bool TextureManager::_loadTexture(const std::string fileName) {

    auto texture = new sf::Texture();
    
    if (texture->loadFromFile(fileName)) {
        _textures[fileName] = std::shared_ptr<sf::Texture>(texture);
        return true;
    } else {
        return false;
    }
 
}

bool TextureManager::_textureLoaded(const std::string fileName) {
    return _textures.find(fileName) != _textures.end();
}

std::weak_ptr<sf::Texture> TextureManager::getTexture(const std::string fileName) {
    if (_textureLoaded(fileName)) {
        return _textures[fileName];
    } else {
        if (_loadTexture(fileName)) {
            return _textures[fileName];
        } else {
            return std::weak_ptr<sf::Texture>();
        }
    }

}