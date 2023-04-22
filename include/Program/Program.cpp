#include "Program.hpp"

void Program::initData(){

}

void Program::initShapes(){

}

void Program::initWindow(){
    this->videoMode = sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT);
    this->window = new sf::RenderWindow(this->videoMode, "Infinite plane", sf::Style::Default);
    this->window->setPosition(sf::Vector2i(
        (sf::VideoMode::getDesktopMode().width - WINDOW_WIDTH)/2,
        (sf::VideoMode::getDesktopMode().height - WINDOW_HEIGHT)/2));
    this->window->setFramerateLimit(FPS);
}


void Program::delShapes(){

}

Program::Program(){
    this->initData();
    this->initShapes();
    this->initWindow();
}

Program::~Program(){
    this->delShapes();

    delete this->window;
    printf("Application closed correctly!\n");
}

void Program::pollEvent(){
    while(this->window->pollEvent(this->currentEvent)){
        switch (this->currentEvent.type){
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            if(this->currentEvent.key.code == sf::Keyboard::Escape)
                this->window->close();
            break;
        case sf::Event::MouseButtonPressed:
            if(this->currentEvent.mouseButton.button == sf::Mouse::Left){
                // add new rectangle
            }
            else if(this->currentEvent.mouseButton.button == sf::Mouse::Right){
                // remove rectangle if contains mouse pos
            }
            break;
        default:
            break;
        }
    }
}

void Program::update(){
    this->pollEvent();

}

void Program::render(){
    this->window->clear(sf::Color(30,30,30));

    this->window->display();
}

const bool Program::running() const{
    return this->window->isOpen();
}
