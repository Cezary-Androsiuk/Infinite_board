#ifndef PLANE_HPP
#define PLANE_HPP
#include "../include.hpp"

class Plane{
    sf::Vector2f position;
    sf::Vector2f positionError;
    
    sf::RectangleShape rs;
    
    void initData(const sf::Vector2u&);
    void initShapes();
public:
    Plane(const sf::Vector2u&);
    ~Plane();

    void updateObjectPos();
public:
    void move(const sf::Vector2f&);

    void update();
    void render(sf::RenderTarget*);
};

#endif