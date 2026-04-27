#include "render/sfml_render.h"
#include "gravitation.h"
#include <cmath>
#include <vector>

float Body::updateRadius(float mass){
    if ( mass < 5 )
        return 5.f;
    
    if ( mass < 15)
        return 10.f;

    if ( mass < 100 )
        return 15.f;

    return 25.f;
}

void Simulation::init(float M, float m, float v, float r){
    Body sun;
    sun.x = 400;
    sun.y = 300;
    sun.vx = 0;
    sun.vy = 0;
    sun.m = M;
    sun.radius = sun.updateRadius(M);
    sun.color = sf::Color::Red;

    Body planet;
    planet.x = sun.x;
    planet.y = sun.y - r;
    planet.vx = v;
    planet.vy = 0;
    planet.m = m;
    planet.radius = planet.updateRadius(m);
    planet.color = sf::Color::Green;

    bodies.push_back(planet);
    bodies.push_back(sun);

}

void Gravity::update(std::vector<Body>& bodies, float dt){
    Body& planet = bodies[0];
    Body& sun = bodies[1];

    float dx = sun.x - planet.x;
    float dy = sun.y - planet.y;

    float r2 = dx * dx + dy * dy;
    if ( r2 < 1e-6f) return;
    
    float r = sqrt(r2);

    float a = 1 * sun.m / (r2 * r);

    float ax = a * dx;
    float ay = a * dy;

    planet.vx += ax * dt;
    planet.vy += ay * dt;

    planet.x += planet.vx * dt;
    planet.y += planet.vy * dt;

}
void Body::render(SFMLRender& r){
    r.drawCircle(x, y, color, radius);
    r.drawLine(400, 300, x, y);
}

void Simulation::update(float dt){
    gravity.update(bodies, dt * 50);
}

void Simulation::render(SFMLRender& r){
    for (auto& b : bodies)
        b.render(r);
}