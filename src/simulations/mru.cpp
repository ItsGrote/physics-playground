#include "simulations/mru.h"


void MRU::update(float dt){
    time += dt;

    x = x0 + v * time;
}

void MRU::render(SFMLRender& r){
    r.drawCircle(x, 300.f);
}