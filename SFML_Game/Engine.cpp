#include "Engine.h"

void Engine::Cycle()
{
    // Loop
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
    sf::Event event;
    switch (window.pollEvent(event))
    {
    case sf::Event::Closed:
            window.close();
            break;
    case sf::Event::KeyPressed:
        switch (event.key.scancode)
        {
        case sf::Keyboard::W:
            break;
        }
        break;
    }

    window.clear();
    window.display();
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
    deltaTime = (end - start).count() / 1000.f;
}

void Engine::Start() {
    while (window.isOpen())
        Cycle();
}