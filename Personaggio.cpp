//
// Created by cosimo on 26/03/19.
//

#include "Personaggio.h"
#include "Mappa.h"
#define TILE 80

Personaggio* Personaggio::instance = 0;

Personaggio::~Personaggio() {
    instance = nullptr;

}

Personaggio *Personaggio::Instance() {
    if(!instance)
        instance= new Personaggio;
    return instance;
}

Personaggio::Personaggio() {
    srand((unsigned int)time(NULL));
    texture.loadFromFile("pacman.png");
    sprite.setTexture(texture);
    sprite.scale(0.20,0.20);
    x=rand()%Mappa::Instance()->getWidth();
    y=rand()%Mappa::Instance()->getHeight();
    sprite.setPosition(x*TILE,y*TILE);
    index=0;
}

int Personaggio::getX() const {
    return (sprite.getPosition().x);
}

void Personaggio::setX(int x) {
    Personaggio::x = x;
}

int Personaggio::getY() const {

    return (sprite.getPosition().y);
}

void Personaggio::setPos() {
    if(index!=pers.size())
    Personaggio::sprite.setPosition(pers[index++]);
}

void Personaggio::drawPersonaggio(RenderWindow &window) {
    window.draw(sprite);

}

const vector<Vector2f> &Personaggio::getPers() const {
    return pers;
}

void Personaggio::setPers(int x,int y) {
    Personaggio::pers.push_back(Vector2f(x,y));
}

void Personaggio::setPos(int x, int y) {
    sprite.setPosition(x,y);

}
