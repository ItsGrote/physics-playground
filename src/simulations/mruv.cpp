#include "simulations/mruv.h"
#include "render/sfml_render.h"
#include "core/vector2d.h"

void MRUV::update(float dt){
    time += dt;
    x = x0 + v0 * time + 0.5f * a * time * time;
}

void MRUV::render(SFMLRender& r){
    Vector2D pos(x, 302.f);
    Vector2D vel(v0 + a * time, 0);

    float scale = 2.f;

    Vector2D vScaled = vel * scale;
    Vector2D vFinal = vScaled.clampMin(10);

    r.drawCircle(x, 295.f);
    r.drawVector(pos, vFinal);

}