#pragma once
#include <vector>
#include "GameObject.h"

class ControllableGameObject : public GameObject
{
private:
	static std::vector<ControllableGameObject*> controlQueue;
	
	bool status = false;
	
	ControllableGameObject() {}
public:
	ControllableGameObject(
		sf::Texture& texture,
		Transforms transforms,
		sf::Vector2f origin
	) : GameObject(texture, transforms, origin) {
		controlQueue.push_back(this);
	}

	ControllableGameObject(
		sf::Texture& texture,
		Transforms transforms,
		sf::Vector2f origin,
		sf::IntRect rect
	) : GameObject(texture, transforms, origin, rect) {
		controlQueue.push_back(this);
	}
	~ControllableGameObject() {
		for (std::vector<ControllableGameObject*>::iterator it = controlQueue.begin(); it < controlQueue.end(); it++)
			if ((*it) == this)
			{
				controlQueue.erase(it);
				break;
			}
	}

	void Move(sf::Vector2f deltaPosition)
	{
		Transforms newPosition = transforms;
		newPosition.setPosition(newPosition.getPosition() + deltaPosition);

		this->setTransforms(newPosition);
	}

	void Control(sf::Event event, float deltaTime) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			// left key is pressed: move our character
			Move({ 0.f, -0.1f * deltaTime });
		}
	}

	static void ControlAll(sf::Event event, float deltaTime)
	{
		for (ControllableGameObject* ob : controlQueue)
			ob->Control(event, deltaTime);
	}
};

