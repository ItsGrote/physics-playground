#include "simulations/mru.h"
#include "core/vector2d.h"


void MRU::update(float dt){
    time += dt;

    
    x = x0 + v * time;
}

void MRU::render(SFMLRender& r){
    Vector2D pos(x, 305.f);
    Vector2D vel(v, 0);

    float scale = 2.f;

    Vector2D vScaled = vel * scale;
    Vector2D vFinal = vScaled.clampMin(10);

    r.drawCircle(x, 300.f);
    r.drawVector(pos, vFinal);
}