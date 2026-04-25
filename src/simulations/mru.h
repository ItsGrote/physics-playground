#pragma once
#include "render/sfml_render.h"

class MRU{
public:
    float x0;
    float v;


    void  update(float dt);
    void render(SFMLRender& r);

private:
    float  time{0.f};
    float x{0.f};

};