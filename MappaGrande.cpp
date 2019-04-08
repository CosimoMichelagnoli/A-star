//
// Created by cosimo on 30/03/19.
//

#include <iostream>
#include "MappaGrande.h"

MappaGrande::MappaGrande() {
    height=25;
    width=25;
    cout<<"bonnnn"<<endl;
    type.push_back(1);
    type.push_back(1);
    type.push_back(1);
    type.push_back(5);
    type.push_back(6);
    type.push_back(9);
    setMappa();
}

