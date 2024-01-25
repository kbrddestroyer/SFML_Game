#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>

#include "Engine.h"
#include "ControllableGameObject.h"

int main() {
	Engine engine;

	sf::Texture texture;
	if (!texture.loadFromFile("idle.png"))
	{
		// error...
		return 0;
	}
	ControllableGameObject object(texture, Transforms(), sf::Vector2f(), sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(64, 128)));

	engine.Start();

	return 0;
}