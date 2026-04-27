#pragma once 
#include <SFML/Graphics.hpp>

class SFMLRender{
public:
    SFMLRender(int w, int h, const char * title);

    bool isOpen();
    void handleEvents();
    void clear();
    void display();

    void drawCircle(float x, float y, sf::Color color = sf::Color::White, float radius = 5.f);
    void drawLine(float oX, float oY, float x, float y);

private:
    sf::RenderWindow window;
};