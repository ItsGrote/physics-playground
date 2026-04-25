#pragma once
#include "render/sfml_render.h"
#include <SFML/Graphics.hpp>

template <typename Sim>
void runSimulation(Sim& sim, const char * title){
    SFMLRender render(800, 600, title);
    sf::Clock clock;

    while (render.isOpen()) {
        float dt = clock.restart().asSeconds();

        render.handleEvents();

        sim.update(dt);

        render.clear();
        sim.render(render);
        render.display();
    }
}

