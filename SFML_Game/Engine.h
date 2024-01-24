#pragma once
#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>

#include <chrono>

#include "Globals.h"

class Engine final
{
private:
	sf::RenderWindow window;
	float deltaTime;
	void Cycle();

public:
	Engine() : window(sf::VideoMode(WIDTH, HEIGHT), "Default") {}
	Engine(unsigned int width, unsigned int height, std::string label = "Default") 
		: window(sf::VideoMode(width, height), label) {}

	~Engine() { window.close(); }

	void Start();
};

