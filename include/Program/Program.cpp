#include "Program.hpp"


void Program::loadSources(){
    if(!this->move_borders.loadFromFile("sources/move_borders.png")){
        exit(1);
    }
    this->move_borders.setSmooth(false);
    this->move_borders.setRepeated(false);

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
    const float scale = 0.5f;
    const unsigned int partTextureWidth = (this->move_borders.getSize().x / 2) * scale;
    const unsigned int partTextureHeight = (this->move_borders.getSize().y / 2) * scale;

    for(int i=0; i<20; i++){
        this->leftSide.push_back(new sf::Sprite(this->move_borders));
        this->leftSide.back()->setPosition(sf::Vector2f(0.f, 20.f + partTextureHeight*i));
        this->leftSide.back()->setTextureRect(sf::IntRect(
            sf::Vector2i(0,0), sf::Vector2i(50,50)));
    }
    // this->leftSide.back()->setPosition(sf::Vector2f(0.f, this->window->getSize().y - 20.f - partTextureHeight));
    (*this->leftSide.begin())->setTextureRect(sf::IntRect(
        sf::Vector2i(0,50), sf::Vector2i(50,50)));
    this->leftSide.back()->setTextureRect(sf::IntRect(
        sf::Vector2i(50,0), sf::Vector2i(50,50)));
    for(sf::Sprite* s : this->leftSide){
        s->setScale(sf::Vector2f(scale, scale));
        s->setColor(sf::Color(255,255,255,100));
    }



    this->rightSide.push_back(new sf::Sprite(this->move_borders));
    this->rightSide.back()->setPosition(sf::Vector2f(this->window->getSize().x, 20.f + partTextureHeight));
    this->rightSide.back()->setTextureRect(sf::IntRect(
        sf::Vector2i(50,0),
        sf::Vector2i(50,50)
    ));
    this->rightSide.back()->setRotation(180);
    for(int i=0; i<18; i++){
        this->rightSide.push_back(new sf::Sprite(this->move_borders));
        this->rightSide.back()->setPosition(sf::Vector2f(this->window->getSize().x - partTextureWidth, 20.f + partTextureHeight*(i+1)));
        this->rightSide.back()->setTextureRect(sf::IntRect(
            sf::Vector2i(0,0),
            sf::Vector2i(50,50)
        ));
    }
    this->rightSide.push_back(new sf::Sprite(this->move_borders));
    this->rightSide.back()->setPosition(sf::Vector2f(this->window->getSize().x, this->window->getSize().y - 20.f));
    this->rightSide.back()->setTextureRect(sf::IntRect(
        sf::Vector2i(0,50),
        sf::Vector2i(50,50)
    ));
    this->rightSide.back()->setRotation(180);
    for(sf::Sprite* s : this->rightSide){
        s->setScale(sf::Vector2f(scale, scale));
        s->setColor(sf::Color(255,255,255,100));
    }



    this->topSide.push_back(new sf::Sprite(this->move_borders));
    this->topSide.back()->setPosition(sf::Vector2f(30.f + partTextureWidth, 0.f));
    this->topSide.back()->setTextureRect(sf::IntRect(
        sf::Vector2i(50,0),
        sf::Vector2i(50,50)
    ));
    this->topSide.back()->setRotation(90);
    for(int i=0; i<34; i++){
        this->topSide.push_back(new sf::Sprite(this->move_borders));
        this->topSide.back()->setPosition(sf::Vector2f(30.f + partTextureWidth*(i+1), 0.f));
        this->topSide.back()->setTextureRect(sf::IntRect(
            sf::Vector2i(0,0),
            sf::Vector2i(50,50)
        ));
    }
    this->topSide.push_back(new sf::Sprite(this->move_borders));
    this->topSide.back()->setPosition(sf::Vector2f(this->window->getSize().x - 30.f, 0.f));
    this->topSide.back()->setTextureRect(sf::IntRect(
        sf::Vector2i(0,50),
        sf::Vector2i(50,50)
    ));
    this->topSide.back()->setRotation(90);
    for(sf::Sprite* s : this->topSide){
        s->setScale(sf::Vector2f(scale, scale));
        s->setColor(sf::Color(255,255,255,100));
    }



    this->bottomSide.push_back(new sf::Sprite(this->move_borders));
    this->bottomSide.back()->setPosition(sf::Vector2f(30.f, this->window->getSize().y));
    this->bottomSide.back()->setTextureRect(sf::IntRect(
        sf::Vector2i(0,50),
        sf::Vector2i(50,50)
    ));
    this->bottomSide.back()->setRotation(-90);
    for(int i=0; i<34; i++){
        this->bottomSide.push_back(new sf::Sprite(this->move_borders));
        this->bottomSide.back()->setPosition(sf::Vector2f(30.f + partTextureWidth*(i+1), this->window->getSize().y - partTextureHeight));
        this->bottomSide.back()->setTextureRect(sf::IntRect(
            sf::Vector2i(0,0),
            sf::Vector2i(50,50)
        ));
    }
    this->bottomSide.push_back(new sf::Sprite(this->move_borders));
    this->bottomSide.back()->setPosition(sf::Vector2f(this->window->getSize().x - 30.f - partTextureWidth, this->window->getSize().y));
    this->bottomSide.back()->setTextureRect(sf::IntRect(
        sf::Vector2i(50,0),
        sf::Vector2i(50,50)
    ));
    this->bottomSide.back()->setRotation(-90);
    for(sf::Sprite* s : this->bottomSide){
        s->setScale(sf::Vector2f(scale, scale));
        s->setColor(sf::Color(255,255,255,100));
    }
}

void Program::delShapes(){
    for(sf::Sprite* s : this->leftSide)
        delete s;
    for(sf::Sprite* s : this->rightSide)
        delete s;
    for(sf::Sprite* s : this->topSide)
        delete s;
    for(sf::Sprite* s : this->bottomSide)
        delete s;
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

    for(sf::Sprite* s : this->leftSide)
        this->window->draw(*s);
    for(sf::Sprite* s : this->rightSide)
        this->window->draw(*s);
    for(sf::Sprite* s : this->topSide)
        this->window->draw(*s);
    for(sf::Sprite* s : this->bottomSide)
        this->window->draw(*s);

    this->window->display();
}

const bool Program::running() const{
    return this->window->isOpen();
}
