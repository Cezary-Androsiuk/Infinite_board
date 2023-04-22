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
            ((this->areaSize.x / this->backgroundTexture->getSize().x) + 3) * this->backgroundTexture->getSize().x, 
            ((this->areaSize.y / this->backgroundTexture->getSize().y) + 3) * this->backgroundTexture->getSize().y)
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
    
    float backgroundWidth = this->position.x;
    float backgroundHeight = this->position.y;

    while(backgroundWidth <= - (float)this->backgroundTexture->getSize().x)
        backgroundWidth += this->backgroundTexture->getSize().x;
    while(backgroundWidth >= (float)this->backgroundTexture->getSize().x)
        backgroundWidth -= this->backgroundTexture->getSize().x;
    backgroundWidth -= this->backgroundTexture->getSize().x;

    while(backgroundHeight <= - (float)this->backgroundTexture->getSize().y)
        backgroundHeight += this->backgroundTexture->getSize().y;
    while(backgroundHeight >= (float)this->backgroundTexture->getSize().y)
        backgroundHeight -= this->backgroundTexture->getSize().y;
    backgroundHeight -= this->backgroundTexture->getSize().y;


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