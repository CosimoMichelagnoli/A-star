//
// Created by cosimo on 26/03/19.
//

#include "Personaggio.h"
#include "Mappa.h"

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
    x=0;
    y=0;
}

int Personaggio::getX() const {
    srand((unsigned int)time(NULL));
    return rand()%Mappa::Instance()->getWidth();
}

void Personaggio::setX(int x) {
    Personaggio::x = x;
}

int Personaggio::getY() const {
    srand((unsigned int)time(NULL));
    return rand()%Mappa::Instance()->getHeight();
}

void Personaggio::setY(int y) {
    Personaggio::y = y;
}
