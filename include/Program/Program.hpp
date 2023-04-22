#ifndef PROGRAM_HPP
#define PROGRAM_HPP
#include "../include.hpp"

class Program{
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event currentEvent;

    sf::RectangleShape moveBorders[4];

    void loadSources();
    void initData();
    void initWindow();
    void initShapes();
    
    void delShapes();
public:
    Program();
    ~Program();

    void pollEvent();
    
public:

    void update();
    void render();

    const bool running() const;
};

#endif