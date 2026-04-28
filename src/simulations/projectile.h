#pragma once
#include "render/sfml_render.h"

class Projectile{
public:
    float x0, y0;
    float v0;
    float g;
    float angle;

    void update(float dt);
    void render(SFMLRender& r);
    
private:
    float time{0.f};
    float x{0.f};
    float y{0.f};
    float vx{0.f};
    float vy{0.f};

};