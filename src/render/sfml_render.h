#pragma once 
#include <SFML/Graphics.hpp>

class SFMLRender{
public:
    SFMLRender(int w, int h, const char * title);

    bool isOpen();
    void handleEvents();
    void clear();
    void display();

    void drawCircle(float x, float y);
    void drawLine(float oX, float oY, float x, float y);

private:
    sf::RenderWindow window;
};