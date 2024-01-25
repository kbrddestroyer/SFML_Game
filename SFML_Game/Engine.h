#pragma once
#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>

#include <chrono>

#include "Globals.h"
#include "Renderer.h"

class Engine final
{
private:
	sf::RenderWindow window;
	float deltaTime;

	void Cycle();
public:
	Engine() : window(sf::VideoMode(WIDTH, HEIGHT), "Default"), deltaTime(0) { }
	Engine(unsigned int width, unsigned int height, std::string label = "Default") 
		: window(sf::VideoMode(width, height), label), deltaTime(0) {
	}

	~Engine() { window.close(); }

	void Start();
};

