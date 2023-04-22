#include "Plane.hpp"



void Plane::initData(const sf::Vector2u& pos){
    this->position = sf::Vector2f(0.f,0.f);
    this->positionError = sf::Vector2f(pos.x / 2.f, pos.y / 2.f);
}
void Plane::initShapes(){
    this->updateObjectPos();
    this->rs.setSize(sf::Vector2f(100.f, 100.f));
}

Plane::Plane(const sf::Vector2u& pos){
    this->initData(pos);
    this->initShapes();
}
Plane::~Plane(){
    
}

void Plane::updateObjectPos(){
    this->rs.setPosition(sf::Vector2f(
        this->position.x + this->positionError.x,
        this->position.y + this->positionError.y
    ));
}

void Plane::move(const sf::Vector2f& moveVector){
    this->position.x += moveVector.x;
    this->position.y += moveVector.y;
}

void Plane::update(){
    this->updateObjectPos();
}
void Plane::render(sf::RenderTarget* window){
    window->draw(this->rs);
}