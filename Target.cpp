//
// Created by cosimo on 06/04/19.
//

#include "Target.h"
Target* Target::instance = 0;



Target *Target::Instance() {
    if(!instance)
        instance= new Target;
    return instance;
}

int Target::getX() const {
    return (sprite.getPosition().x);
}

void Target::setX(int x) {
    Target::x = x;
}

int Target::getY() const {
    return (sprite.getPosition().y);
}

void Target::setY(int y) {
    this->y=y;
}

void Target::drawPersonaggio(RenderWindow &window) {
    window.draw(sprite);

}

Target::Target() {
    texture.loadFromFile("index.png");
    sprite.setTexture(texture);
    sprite.scale(0.35,0.35);

}
Target::~Target() {
    instance = nullptr;

}
void Target::setpos(int x, int y ) {
    Target::sprite.setPosition(x,y);
}