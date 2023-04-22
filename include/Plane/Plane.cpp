#include "Plane.hpp"



void Plane::initData(const sf::Vector2u& windowSize, const sf::Texture* bgTex){
    this->backgroundTexture = bgTex;
    this->background.setTexture(*this->backgroundTexture);

    this->areaSize = windowSize;

    this->position = sf::Vector2f(0.f,0.f);
    this->positionError = sf::Vector2u(this->areaSize.x / 2, this->areaSize.y / 2);
}
void Plane::initShapes(){
    this->updateObjectPos();
    this->rs.setSize(sf::Vector2f(100.f, 100.f));

    this->background.setTextureRect(sf::IntRect(
        sf::Vector2i(0,0),
        sf::Vector2i( // set size of sprite that is divided by texture size 
            ((this->areaSize.x / this->backgroundTexture->getSize().x) + 2) * this->backgroundTexture->getSize().x, 
            ((this->areaSize.y / this->backgroundTexture->getSize().y) + 2) * this->backgroundTexture->getSize().y)
    ));
}

Plane::Plane(const sf::Vector2u& windowSize, const sf::Texture* bgTex){
    this->initData(windowSize, bgTex);
    this->initShapes();
}
Plane::~Plane(){
    
}

void Plane::updateObjectPos(){
    this->rs.setPosition(sf::Vector2f(
        this->position.x + this->positionError.x,
        this->position.y + this->positionError.y
    ));
    // this multiply by 100 keeps float precision 
    const float backgroundWidth = (((int)(this->position.x*100.f)) % (this->backgroundTexture->getSize().x * 100))/100.f - 
        this->backgroundTexture->getSize().x;
    const float backgroundHeight = (((int)(this->position.y*100.f)) % (this->backgroundTexture->getSize().y * 100))/100.f - 
        this->backgroundTexture->getSize().y;
    this->background.setPosition(sf::Vector2f(
        backgroundWidth,
        backgroundHeight
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
    window->draw(this->background);
    window->draw(this->rs);
}