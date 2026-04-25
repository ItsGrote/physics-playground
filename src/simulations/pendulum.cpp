#include "pendulum.h"
#include "render/sfml_render.h"
#include <cmath>

float Pendulum::degToRad(float deg){
    return deg * (M_PI / 180.0f);
}

void Pendulum::init(float m, float g, float l){
    this->m = m;
    this->g = g;
    this->l = l;

    float angle0 = 30.0f;
    this->angle = degToRad(angle0);

    prevAngle = this->angle;
}

void Pendulum::update(float dt){
    float a = - ( g / l ) * sin(angle);

    float newAngle = 2 * angle - prevAngle + a * dt * dt;

    prevAngle = angle;
    angle = newAngle;
}

void Pendulum::render(SFMLRender& r){
    float x = originX +  l * sin(angle);
    float y = originY + l * cos(angle);

    r.drawLine(originX, originY, x, y);
    r.drawCircle(x, y);
}