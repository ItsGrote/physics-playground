#include "render/sfml_render.h"
#include <SFML/Graphics/Color.hpp>
#include <vector>

class Mass{
public:
    float m;
    float v;
    float x0;
    float radius;
    sf::Color color;

    float updateRadius(float mass);
    void render(SFMLRender& r);

private:
    float x{0.f};
};

class Collision{
public:
    float  e;
    bool hasCollided = false;

    void update(std::vector<Mass>& bodies, float dt);

};

class SimulationCol{
public:
    void init(float m1, float m2, float v1, float v2, float e);
    void update(float dt);
    void render(SFMLRender& r);

private:
    std::vector<Mass> bodies;
    Collision collision;
};