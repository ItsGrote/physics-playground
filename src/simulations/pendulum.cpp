#include "pendulum.h"
#include "render/sfml_render.h"
#include "core/vector2d.h"
#include <cmath>

float Pendulum::updateRope(float length){
    if (length < 50)
        return 100;
    return 0;
}

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

    float oldAngle = angle;

    float a = - ( g / l ) * sin(angle);

    float newAngle = 2 * angle - prevAngle + a * dt * dt;

    w = (oldAngle - prevAngle) / dt;

    prevAngle = angle;
    angle = newAngle;

}

void Pendulum::render(SFMLRender& r){
    float x = originX +  l * sin(angle);
    float y = originY + l * cos(angle);

    Vector2D pos(x, y);

    float a = -(g / l) *  sin(angle);

    Vector2D acc(
        -a * l * sin(angle),
         a * l * cos(angle)
    );
    Vector2D vel(
         - w * l * cos(angle),
          w * l * sin(angle)
    );

    float scale = 0.5f;

    Vector2D accFinal = (acc * scale).clampMin(10);
    Vector2D velFinal = (vel * scale).clampMin(10);

    r.drawLine(originX, originY, x, y);
    r.drawCircle(x, y);
    r.drawVector(pos, accFinal);
    r.drawVector(pos, velFinal);
}