#include "simulations/projectile.h"
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
    r.drawCircle(x, 500 - y);
}
