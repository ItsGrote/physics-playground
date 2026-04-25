#pragma once
#include "render/sfml_render.h"

class MRUV{
public:
    float x0;
    float v0;
    float a;

    void update(float dt);
    void render(SFMLRender& r);

private:
    float time{0.f};
    float x{0.f};
};