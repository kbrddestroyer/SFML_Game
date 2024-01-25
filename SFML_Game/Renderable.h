#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Renderable {
private:
	static std::vector<Renderable*> renderQueue;
	unsigned int id;
public:
	Renderable() : id(getID()) { Renderable::renderQueue.push_back(this); }
	~Renderable() {
		for (std::vector<Renderable*>::iterator it = renderQueue.begin(); it < renderQueue.end(); it++)
			if ((*it) == this)
			{
				renderQueue.erase(it);
				break;
			}
	}
	unsigned int getID() {
		static unsigned int id = 0;
		return id++;
	}

	static void RenderAll(sf::RenderWindow&);

	virtual void Render(sf::RenderWindow&) = 0;

	bool operator== (const Renderable& other) { return id == other.id; }
};
