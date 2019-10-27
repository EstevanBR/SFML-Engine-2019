#include <SFML/Graphics.hpp>
#include "MyGame.hpp"

int main() {
	return MyGame().main(sf::VideoMode(640,480), "MyGame", sf::Style::Titlebar|sf::Style::Close);	
}
