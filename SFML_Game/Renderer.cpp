#include "Renderer.h"

std::vector<Renderable*> Renderable::renderQueue;

void Renderable::RenderAll(sf::RenderWindow& window) {
	for (Renderable* renderable : renderQueue)
		renderable->Render(window);
}
