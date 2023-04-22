#ifndef PROGRAM_HPP
#define PROGRAM_HPP
#include "../include.hpp"

class Program{
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event currentEvent;

    void initData();
    void initShapes();
    void initWindow();
    
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