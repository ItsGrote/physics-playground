#include "render/sfml_render.h"
#include "simulations/collision.h"
#include "core/vector2d.h"
#include<vector>
#include<cmath>

float Mass::updateRadius(float mass){
    if ( mass < 5 )
        return 5.f;
    
    if ( mass < 15)
        return 10.f;

    if ( mass < 100 )
        return 15.f;

    return 25.f;
}

void SimulationCol::init(float m1, float m2, float v1, float v2, float e){
    Mass firstBody;
    firstBody.m = m1;
    firstBody.v = v1;
    firstBody.x0 = 100.0f;
    firstBody.color = sf::Color::Red;
    firstBody.radius = firstBody.updateRadius(m1);

    Mass secondBody;
    secondBody.m = m2;
    secondBody.v = v2;
    secondBody.x0 = 400.0f;
    secondBody.color = sf::Color::Green;
    secondBody.radius = secondBody.updateRadius(m2);

    collision.e = e;


    bodies.push_back(firstBody);
    bodies.push_back(secondBody);
}

void Collision::update(std::vector<Mass>& bodies, float dt){
    Mass& firstBody = bodies[0];
    Mass& secondBody = bodies[1];

    float dx = secondBody.x0 - firstBody.x0;

    float v1 = firstBody.v;
    float m1 = firstBody.m;

    float v2 = secondBody.v;
    float m2 = secondBody.m;

    float r1 = firstBody.radius;
    float r2 = secondBody.radius;

    if (!hasCollided && abs(dx) <= (r1 + r2)){
        hasCollided = true;

        firstBody.v = (m1*v1 + m2*v2 - m2*e*(v1 - v2))/(m1 + m2);

        secondBody.v = (m1*v1 + m2*v2 + m1*e*(v1 - v2))/(m1 + m2);
    }


    firstBody.x0 += firstBody.v * dt;
    secondBody.x0 += secondBody.v * dt;

}

void Mass::render(SFMLRender& r){
    Vector2D pos(x0, 309);
    Vector2D vel(v, 0);

    float scale = 10.f;

    Vector2D vScaled = vel * scale;
    Vector2D vFinal = vScaled.clampMin(10);

    r.drawCircle(x0, 300, color, radius);
    r.drawVector(pos, vFinal);
}

void SimulationCol::update(float dt){
    collision.update(bodies, 25 * dt);
}

void SimulationCol::render(SFMLRender& r){
    for( auto& b : bodies )
        b.render(r);
}