//
// Created by cosimo on 30/03/19.
//

#include <iostream>
#include "MappaGrande.h"

MappaGrande::MappaGrande() {
    height=25;
    width=25;
    type.push_back(1);
    type.push_back(1);
    type.push_back(1);
    type.push_back(6);
    type.push_back(7);
    type.push_back(9);
    setMappa();
}

