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

sf::Color SFMLRender::getColorbyMagnitude(float mag){
    float maxMag = 100.f;
    float t = std::min (mag / maxMag, 1.f);

    sf::Uint8 r = static_cast<sf::Uint8>(255 * t);
    sf::Uint8 g = 0;
    sf::Uint8 b = static_cast<sf::Uint8>(255 * (1 - t));

    return sf::Color(r, g, b);
}

void SFMLRender::drawVector(const Vector2D& origin, const Vector2D& v){
    float mag = v.magnitude();
    sf::Color color = getColorbyMagnitude(mag);

    Vector2D end = origin + v;

    sf::Vertex line[] = {
        sf::Vertex(sf::Vector2f(origin.x, origin.y), color),
        sf::Vertex(sf::Vector2f(end.x, end.y), color)
    };

    window.draw(line, 2, sf::Lines);

    Vector2D dir = v.normalized();

    Vector2D perp(-dir.y, dir.x);

    float arrowSize = 10.f; 

    Vector2D left  = end - dir * arrowSize + perp * (arrowSize * 0.5f);
    Vector2D right = end - dir * arrowSize - perp * (arrowSize * 0.5f);

    sf::Vertex arrow[] = {
        sf::Vertex(sf::Vector2f(end.x, end.y), color),
        sf::Vertex(sf::Vector2f(left.x, left.y), color),

        sf::Vertex(sf::Vector2f(end.x, end.y), color),
        sf::Vertex(sf::Vector2f(right.x, right.y), color)
    };

    window.draw(arrow, 4, sf::Lines);
}