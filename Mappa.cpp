//
// Created by cosimo on 26/03/19.
//

#include "Mappa.h"
#include "MappaSiepi.h"
#include "MappaPietre.h"
//#include <sstream>
#include <fstream>
#include <iostream>


void Mappa::setMappa() {
    //fstream mapTextFile;
    //mapTextFile.open(nameflie);

    //int i=0;
    //string line;
    vector <Tile> lineTiles;//oggetti di tipo tile
    Tile tile;
    srand((unsigned int)time(NULL));
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            tile.setValue(type[rand()%type.size()]);
            if(tile.getValue()<50)
                tile.setWall(true);
            tile.setWall(false);
            lineTiles.push_back(tile);
            cout<<tile.getValue()<<" ";
        }
        cout<<endl;
        tiles.push_back(lineTiles);//vettore di vettori
        lineTiles.clear();
    }

    /*while(getline(mapTextFile,line)) { per una mappa prestabilita

        istringstream iss(line);

        while(iss>>i) {

            tile.setValue(i); //DA IL VALORE ALL'OGGETTO TILE UGUALE al valore del file di testo in quel punto

            if (i <100)
                tile.setWall(false);
            else
                tile.setWall(true); //per settare alla tile se è camminabile o no

            lineTiles.push_back(tile);
        }

        tiles.push_back(lineTiles);//vettore di vettori
        lineTiles.clear();
    }

    mapTextFile.close();*/
}

void Mappa::drawMap() {

}

Mappa* Mappa::instance = 0;

int Mappa::getHeight() const {

    return height;
}

int Mappa::getWidth() const {

    return width;
}
bool Mappa::getTileWall(int x, int y) {

    return tiles[x][y].getWall();
}

int Mappa::getTileValue(int x, int y) {
    return tiles[x][y].getValue();
}

/*Mappa::Mappa(string namefile) {
    this->namefile=namefile;
    setMappa();
    setGoal();

}*/

Mappa::~Mappa() {
    instance = nullptr;

}

Mappa *Mappa::Instance(int num) {
    if(!instance)
        switch(num) {
        case 0:   instance = new MappaSiepi;
        break;
        case 1:   instance = new MappaPietre;
        break;
        /*default:
            cout<<"errore"; mettere exeption*/
        }
    return instance;
}

void Mappa::setGoal() {
    do{
        goalx=random()%height;
        goaly=random()%width;
    }
    while (!tiles[goalx][goaly].getWall());

}

Mappa::Mappa() {

}

