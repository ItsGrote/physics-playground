#pragma once
#include "render/sfml_render.h"

class Spring{
public:
    float m;
    float k;
    float radius;

    float updateRadius(float mass);
    void init(float m, float k);
    void update(float dt);
    void render(SFMLRender& r);

private:
    float time{0.f};
    float x{500.f};
    float w;
    float v{0.f};
    float A{50.f};
};