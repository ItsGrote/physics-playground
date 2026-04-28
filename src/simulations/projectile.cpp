#include "simulations/projectile.h"
#include "core/vector2d.h"
#include<cmath>
#include "render/sfml_render.h"

void Projectile::update(float dt){
    time += dt;
    float theta = angle * (M_PI / 180.0f);

    float v0x = v0 * cos(theta);
    float v0y = v0 * sin(theta);

    x = x0 + v0x * time;

    y = y0 + v0y * time - 0.5f * g * time * time;
}

void Projectile::render(SFMLRender& r){
    float theta = angle * (M_PI / 180.0f);

    Vector2D pos(x, 500 - y);
    Vector2D vel(v0 * cos(theta), -(v0 * sin(theta) - g * time));
    Vector2D velHorizontal(v0 * cos(theta), 0);
    Vector2D velVertical(0, -(v0 * sin(theta) - g * time));

    r.drawCircle(x, 500 - y);
    r.drawVector(pos, vel);
    r.drawVector(pos, velHorizontal);
    r.drawVector(pos, velVertical);
}
