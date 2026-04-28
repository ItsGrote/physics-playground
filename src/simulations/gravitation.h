#include "render/sfml_render.h"
#include "core/vector2d.h"
#include <vector>
#include <cmath>

class Body{
public:
    float x ,y;
    float vx, vy;
    float m;
    float radius;

    Vector2D force{0.f, 0.f};
    sf::Color color;

    float updateRadius(float mass);
    void render(SFMLRender& r);
};

class Gravity{
public:
    void update(std::vector<Body>& bodies, float dt);


};

class Simulation{
public:
    void init(float M, float m, float v0, float r);
    void update(float dt);
    void render(SFMLRender& r);

private:
    std::vector<Body> bodies;
    Gravity gravity;
};