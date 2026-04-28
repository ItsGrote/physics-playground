#pragma once 
#include <SFML/Graphics.hpp>
#include "core/vector2d.h"

class SFMLRender{
public:
    SFMLRender(int w, int h, const char * title);

    bool isOpen();
    void handleEvents();
    void clear();
    void display();

    void drawCircle(float x, float y, sf::Color color = sf::Color::White, float radius = 10.f);
    void drawLine(float oX, float oY, float x, float y);
    void drawVector(const Vector2D& origin, const Vector2D& v);

    sf::Color getColorbyMagnitude(float mag);

private:
    sf::RenderWindow window;
};