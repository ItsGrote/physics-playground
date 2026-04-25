#include "render/sfml_render.h"

class Pendulum{
public:
    float l;
    float g;
    float m;

    float angle;
    float prevAngle;

    float originX{400.f};
    float originY{100.f};

    void init(float m, float g, float l);
    void update(float dt);
    void render(SFMLRender& r);

private:
    float degToRad(float deg);

};