#ifndef PROGRAM_HPP
#define PROGRAM_HPP
#include "../include.hpp"
#include "../Plane/Plane.hpp"

class Program{
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event currentEvent;

    sf::RectangleShape moveBorders[4];

    Plane* plane;

    void loadSources();
    void initData();
    void initWindow();
    void initShapes();
    
    void delShapes();
public:
    Program();
    ~Program();

    void pollEvent();
    
    void updatePlanePos();
public:

    void update();
    void render();

    const bool running() const;
};

#endif