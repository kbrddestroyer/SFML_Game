#pragma once
#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>

class Transforms
{
private:
	sf::Vector2f position;
	float rotation;
	sf::Vector2f scale;
public:
	Transforms(sf::Vector2f position = sf::Vector2f(100, 100), float rotation = 0.f, sf::Vector2f scale = sf::Vector2f(1, 1))
		: position(position), rotation(rotation), scale(scale) {}

	sf::Vector2f getPosition() { return position; }
	sf::Vector2f getScale() { return scale; }
	float getRotation() { return rotation; }

	void setPosition(sf::Vector2f position) { this->position = position; }
	void setScale(sf::Vector2f scale) { this->scale = scale; }
	void setRotation(float rotation) { this->rotation; }
};

