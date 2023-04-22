#ifndef PLANE_HPP
#define PLANE_HPP
#include "../include.hpp"

class Plane{
    sf::Vector2f position;
    sf::Vector2u positionError;
    sf::Vector2u areaSize;
    
    const sf::Texture* backgroundTexture;
    sf::Sprite background;

    sf::RectangleShape rs;
    
    void initData(const sf::Vector2u&, const sf::Texture*);
    void initShapes();
public:
    Plane(const sf::Vector2u&, const sf::Texture*);
    ~Plane();

    void updateObjectPos();
public:
    void move(const sf::Vector2f&);

    void update();
    void render(sf::RenderTarget*);
};

#endif