//
// Created by cosimo on 26/03/19.
//

#include "Tile.h"
Tile::Tile() = default;

void Tile::setValue(int val) {

    value=val;
}

int Tile::getValue() {

    return value;
}

void Tile::setWall(bool state) {

    wall=state;
}

bool Tile::getWall() {

    return wall;
}