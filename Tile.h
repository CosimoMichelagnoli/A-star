//
// Created by cosimo on 26/03/19.
//

#ifndef A_STAR_TILE_H
#define A_STAR_TILE_H


class Tile {

public:

    Tile();



    void setCosto(int costo);

    void setValue(int val);

    int getValue();



private:
    int value;
};


#endif //A_STAR_TILE_H
