#include "render/sfml_render.h"

SFMLRender::SFMLRender(int w, int h, const char * title):window(sf::VideoMode(w, h), title){}

bool SFMLRender::isOpen(){
    return window.isOpen();
}

void SFMLRender::handleEvents(){
    sf::Event event;
    while(window.pollEvent(event)){
        if ( event.type == sf::Event::Closed)
            window.close();
    }
}

void SFMLRender::clear(){
    return window.clear();
}
void SFMLRender::display(){
    return window.display();
}

void SFMLRender::drawCircle(float x, float y, sf::Color color, float radius){
    sf::CircleShape c (radius);
    c.setPosition(x, y);
    c.setFillColor(color);
    window.draw(c);
}

void SFMLRender::drawLine(float oX, float oY, float x, float y){
    sf::Vertex line[] =
    {
        sf::Vertex(sf::Vector2f(oX, oY)),
        sf::Vertex(sf::Vector2f(x, y))
    };

    window.draw(line, 2, sf::Lines);
}