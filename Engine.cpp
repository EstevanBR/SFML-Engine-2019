#include "Engine.hpp"

#include "Physics.hpp"
#include "Graphics.hpp"
#include "Input.hpp"
#include "Tree.hpp"
#include "Camera.hpp"

Engine::Engine(Graphics &graphics, Input &input, Physics &physics, Tree &tree, sf::RenderWindow &window, Camera &camera): graphics(graphics), input(input), tree(tree), physics(physics), window(window), camera(camera) {

}