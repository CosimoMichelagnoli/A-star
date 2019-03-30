//
// Created by cosimo on 26/03/19.
//

#include "Personaggio.h"

Personaggio::~Personaggio() {
    instance= nullptr;

}

Personaggio *Personaggio::Instance() {
    if(!instance)
        instance=new Personaggio();
    return instance;
}

Personaggio::Personaggio() {
    x=0;
    y=0;
}
