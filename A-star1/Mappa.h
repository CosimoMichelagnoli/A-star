//
// Created by cosimo on 22/03/19.
//

#ifndef A_STAR_MAPPA_H
#define A_STAR_MAPPA_H


class Mappa {

private:
    int width;
    int heigth;
    int* maplvl;

protected:
    explicit Mappa(int map);

public:
    ~Mappa();
    Mappa();
    void draw();

    static Mappa* Istance(int nmap=1);

    int getMap( int x, int y);

    int getWidth() const {
        return width;
    }

    int getHeight() const {
        return height;
    }


};


#endif //A_STAR_MAPPA_H
