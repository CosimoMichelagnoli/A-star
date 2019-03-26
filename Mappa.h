//
// Created by cosimo on 26/03/19.
//

#ifndef A_STAR_MAPPA_H
#define A_STAR_MAPPA_H
#include <vector>
#include <string>
#include "Tile.h"

using namespace std;

class Mappa {
public:
    Mappa();
    ~Mappa();

    void setMappa();
    void drawMap();
    int getMap( int x, int y);
    static Mappa* Istance(int nmap=1);
    int getTileValue(int x, int y);

    int getWidth() const;

    int getHeight() const;
    bool getTileWall(int x,int y);


protected:
    explicit Mappa(int nummap);

private:
    static Mappa* instance;
    bool loadMap(std::string path, int& height, int& width);

    int width;
    int height;
    int* lvlmap;
    vector<vector<Tile>>tiles;

};


#endif //A_STAR_MAPPA_H
