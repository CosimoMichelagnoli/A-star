//
// Created by cosimo on 26/03/19.
//

#include "Mappa.h"
#include <sstream>
#include <fstream>


void Mappa::setMappa() {

    fstream mapTextFile;
    mapTextFile.open("/home/cosimo/Scrivania/provamappa");

    int i=0;
    string line;
    vector <Tile> lineTiles;//oggetti di tipo tile
    Tile tile;

    while(getline(mapTextFile,line)) {

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

    mapTextFile.close();
}

void Mappa::drawMap() {

}

Mappa* Mappa::instance = nullptr;

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

Mappa::Mappa() {

}

Mappa::~Mappa() {

}

/*Mappa::Mappa(int nummap) {
    switch(nummap) {
        case 1:
            //use absolute path for unit testing
            //loadMap("/home/matti/Documenti/PROGRAMMAZIONEUNI/AStarLabSDL/maps/map1.map",height,width);
            loadMap("../maps/map1.map",height,width);
            break;
            case 2:
                //loadMap("/home/matti/Documenti/PROGRAMMAZIONEUNI/AStarLabSDL/maps/map2.map",height,width);
            loadMap("../maps/map2.map",height,width);
            break;
            case 3:
                //loadMap("/home/matti/Documenti/PROGRAMMAZIONEUNI/AStarLabSDL/maps/map3.map",height,width);
            loadMap("../maps/map3.map",height,width);
            break;
            default:
                //loadMap("/home/matti/Documenti/PROGRAMMAZIONEUNI/AStarLabSDL/maps/map3.map",height,width);
            loadMap("../maps/map3.map",height,width);
            break;

    }
}
*/