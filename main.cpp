#include <SFML/Graphics.hpp>
#include "MyGame.hpp"

int main() {
	return MyGame().main(sf::VideoMode(1920 / 4,1080 / 4), "MyGame", sf::Style::Resize|sf::Style::Close);	
}
