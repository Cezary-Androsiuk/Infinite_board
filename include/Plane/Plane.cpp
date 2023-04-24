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
    for(RectangleShape_Position* rs_p : this->rectangles){
        delete rs_p->rs;
        delete rs_p;
    }
}

void Plane::updateObjectPos(){
    for(RectangleShape_Position* rs_p : this->rectangles)
        rs_p->rs->setPosition(sf::Vector2f(
            this->position.x + rs_p->p.x,
            this->position.y + rs_p->p.y
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
void Plane::addObject(const sf::Vector2f& mousePosition){
    RectangleShape_Position* rs_p = new RectangleShape_Position();
    rs_p->rs = new sf::RectangleShape();
    rs_p->p = sf::Vector2f(mousePosition.x - this->position.x, mousePosition.y - this->position.y);

    rs_p->rs->setSize(sf::Vector2f(40.f, 40.f));
    rs_p->rs->setOrigin(sf::Vector2f(rs_p->rs->getSize().x/2, rs_p->rs->getSize().y/2));
    this->rectangles.push_back(rs_p);
}
void Plane::delObject(const sf::Vector2f& mousePosition){
    for(int i=0; i<this->rectangles.size(); i++){
        if(this->rectangles[i]->rs->getGlobalBounds().contains(mousePosition)){
            delete this->rectangles[i]->rs;
            delete this->rectangles[i];
            this->rectangles.erase(this->rectangles.begin() + i);
        }
    }

}

void Plane::update(){
    this->updateObjectPos();
}
void Plane::render(sf::RenderTarget* window){
    window->draw(this->background);
    for(RectangleShape_Position* rs_p : this->rectangles)
        window->draw(*rs_p->rs);
}