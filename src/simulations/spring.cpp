#include<cmath>
#include "simulations/spring.h"
#include "render/sfml_render.h"
#include "core/vector2d.h"


float Spring::updateRadius(float mass){
    if ( mass < 5 )
    return 5.f;
    
    if ( mass < 15)
    return 10.f;
    
    if ( mass < 100 )
    return 15.f;
    
    return 25.f;
}

void Spring::init(float m, float k){
    this->m = m;
    this->k = k;
    this->radius = updateRadius(this->m);

    this->w = sqrt(k/m);

    this->x = 500.0f;
}

void Spring::update(float dt){

    float dx = x - 400;

    float a = - w * w * dx;

    v += a * dt;
    x += v * dt;
}

void Spring::render(SFMLRender& r){
    Vector2D pos(400, x);
    Vector2D acc(0, w * w * (400 - x));


    float scale = 0.2f;

    Vector2D accScaled = acc * scale;
    Vector2D accFinal = accScaled.clampMin(10);

    r.drawLine(400, 250, 400, x);
    r.drawCircle(400, x, sf::Color::White, radius);
    r.drawVector(pos, accFinal);
}