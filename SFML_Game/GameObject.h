#pragma once
#include <SFML/Graphics.hpp>
#include "Transforms.h"
#include "Renderable.h"

class GameObject : Renderable
{
protected:
	sf::Sprite sprite;
	Transforms transforms;
	GameObject() : sprite(), transforms() { }
public:
	GameObject(
		sf::Texture& texture,
		Transforms transforms,
		sf::Vector2f origin
	) : sprite(texture), transforms(transforms) {
		setTransforms(transforms);
		sprite.setOrigin(origin);
	}
	GameObject(
		sf::Texture& texture,
		Transforms transforms,
		sf::Vector2f origin,
		sf::IntRect rect
	) : sprite(texture), transforms(transforms) {
		setTransforms(transforms);
		sprite.setTextureRect(rect);
		sprite.setOrigin(origin);
	}

	void setTransforms(Transforms transforms)
	{
		sprite.setPosition(transforms.getPosition());
		sprite.setScale(transforms.getScale());
		sprite.setRotation(transforms.getRotation());

		this->transforms = transforms;
	}

	void setTextureRect(sf::IntRect rect)
	{
		sprite.setTextureRect(rect);
	}

	void Render(sf::RenderWindow& window) {
		window.draw(sprite);
	}
}; 

