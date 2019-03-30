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

    void setWall(bool s);

    bool getWall();

    int getCosto() const;

private:
    int costo;
    int value;
    bool wall;//identifica cosa è camminabile
};


#endif //A_STAR_TILE_H
