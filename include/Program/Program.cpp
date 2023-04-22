#include "Program.hpp"


void Program::loadSources(){
    
}

void Program::initData(){

}


void Program::initWindow(){
    this->videoMode = sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT);
    this->window = new sf::RenderWindow(this->videoMode, "Infinite plane", sf::Style::Default);
    this->window->setPosition(sf::Vector2i(
        (sf::VideoMode::getDesktopMode().width - WINDOW_WIDTH)/2,
        (sf::VideoMode::getDesktopMode().height - WINDOW_HEIGHT)/2));
    this->window->setFramerateLimit(FPS);
}

void Program::initShapes(){
    // left
    this->moveBorders[0].setSize(sf::Vector2f(40.f, this->window->getSize().y));
    this->moveBorders[0].setPosition(sf::Vector2f(0.f, 0.f));

    // right
    this->moveBorders[1].setSize(sf::Vector2f(40.f, this->window->getSize().y));
    this->moveBorders[1].setPosition(sf::Vector2f(
        this->window->getSize().x - this->moveBorders[1].getSize().x, 0.f));

    // top
    this->moveBorders[2].setSize(sf::Vector2f(this->window->getSize().x, 40.f));
    this->moveBorders[2].setPosition(sf::Vector2f(0.f, 0.f));

    // bottom
    this->moveBorders[3].setSize(sf::Vector2f(this->window->getSize().x, 40.f));
    this->moveBorders[3].setPosition(sf::Vector2f(
        0.f, this->window->getSize().y - this->moveBorders[3].getSize().y));

    for(sf::RectangleShape& r : this->moveBorders){
        r.setFillColor(sf::Color(255,30,30,60));
    }
}

void Program::delShapes(){
}

Program::Program(){
    this->loadSources();
    this->initData();
    this->initWindow();
    this->initShapes();
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

    for(sf::RectangleShape& r : this->moveBorders)
        this->window->draw(r);

    this->window->display();
}

const bool Program::running() const{
    return this->window->isOpen();
}
