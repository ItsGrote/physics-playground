#include "simulations/mruv.h"
#include "render/sfml_render.h"

void MRUV::update(float dt){
    time += dt;
    x = x0 + v0 * time + 0.5f * a * time * time;
}

void MRUV::render(SFMLRender& r){
    return r.drawCircle(x, 300.f);
}