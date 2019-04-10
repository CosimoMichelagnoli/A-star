//
// Created by cosimo on 26/03/19.
//

#include "Mappa.h"
#include "MappaPiccola.h"
#include "MappaGrande.h"
//#include <sstream>
#include <fstream>
#include <iostream>
#define TILE 80

void Mappa::setMappa() {
    //fstream mapTextFile;
    //mapTextFile.open(nameflie);

    //int i=0;
    //string line;
    //vector <Tile> lineTiles;//oggetti di tipo tile
    //Tile tile;
    lvlmap = new int[width * height];
    //percorso= new char[width * height];
    srand((unsigned int)time(NULL));
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            lvlmap[i*width+j]=type[rand()%type.size()];
            //tile.setValue(type[rand()%type.size()]);
            //lineTiles.push_back(tile);
            //cout<<lvlmap[i*width+j]<<" ";
        }
        //cout<<endl;
        //tiles.push_back(lineTiles);//vettore di vettori
        //lineTiles.clear();
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

void Mappa::drawMap(RenderWindow &window) {
    window.draw(vert, st);

}

Mappa* Mappa::instance = 0;

int Mappa::getHeight() const {
    return height;
}

int Mappa::getWidth() const {
    return width;
}

/*int Mappa::getTileValue(int x, int y) {
    return tiles[x][y].getValue();
}*/

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
        case 0:   instance = new MappaPiccola;
        break;
        case 1:   instance = new MappaGrande;
        break;
        /*default:
            cout<<"errore"; mettere exeption*/
        }
    return instance;
}

/*void Mappa::setGoal() {
    do{
        goalx= static_cast<int>(random() % height);
        goaly= static_cast<int>(random()%width);
    }
    while (lvlmap[goalx*width+goaly]!=9);

}*/

Mappa::Mappa() {}

int Mappa::getMap( int x, int y )
{
    if( x < 0 || x >= width || y < 0 || y >= height) return 60;
    return lvlmap[y * width + x];
}

void Mappa::setLvlmap(int x, int y) {
    //Mappa::lvlmap[y * width + x] = 0;
    //Mappa::percorso[y * width + x] = 'X';

}

/*void Mappa::mostraMappa() {
    for(int i=0;i<width;i++){
        for(int j=0;j<height;j++){
            //cout<<lvlmap[i*width+j]<<" ";
            cout<<percorso[i*width+j]<<"  ";
        }
        cout<<endl;
    }

}*/
bool Mappa::load() {

    // load the map tileset texture

    if (!texture.loadFromFile("../immagini/Spritesheet.PNG"))
        return false;

    // resize the vertex array to fit the tile size

    vert.setPrimitiveType(sf::Quads);

    vert.resize(height * width * 4);

    // populate the vertex array, with one quad per tile

    for (unsigned int i = 0; i < height; i++) {

        for (unsigned int j = 0; j < width; j++) {

            // get the current tile number

            int tileNumber =lvlmap[i*width+j];


            // find its position in the tileset texture

            int tu = tileNumber % (texture.getSize().x / TILE);

            int tv = tileNumber / (texture.getSize().x / TILE);


            // get a pointer to the current tile's quad

            sf::Vertex *quad = &vert[(j + i * width) * 4];

            // define its 4 corners

            quad[0].position = sf::Vector2f(j * TILE, i * TILE);

            quad[1].position = sf::Vector2f((j + 1) * 80, i *80);

            quad[2].position = sf::Vector2f((j + 1) * 80, (i + 1) * 80);

            quad[3].position = sf::Vector2f(j * TILE, (i + 1) * TILE);

            // define its 4 texture coordinates

            quad[0].texCoords = sf::Vector2f(tu * TILE, tv * TILE);

            quad[1].texCoords = sf::Vector2f((tu + 1) * TILE, tv * TILE);

            quad[2].texCoords = sf::Vector2f((tu + 1) * TILE, (tv + 1) * TILE);

            quad[3].texCoords = sf::Vector2f(tu * TILE, (tv + 1) * TILE);

        }
    }

    st.texture=&texture;

    return true;

}

int *Mappa::getLvlmap() const {
    return lvlmap;
}
