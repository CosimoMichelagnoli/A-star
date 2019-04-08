//
// Created by cosimo on 26/03/19.
//

#ifndef A_STAR_PERSONAGGIO_H
#define A_STAR_PERSONAGGIO_H
#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;
using namespace std;

class Personaggio {
public:
    ~Personaggio();

    const vector<Vector2f> &getPers() const;

    void setPers(int x,int y);

    void drawPersonaggio(RenderWindow &window);

    int getX() const;

    void setX(int x);

    int getY() const;

    void setPos();

    void setPos(int x, int y);


    static Personaggio *Instance();


protected:
    Personaggio();

private:
    vector<Vector2f> pers;
    Sprite sprite;
    Texture texture;
    static Personaggio* instance;
    int x;
    int y;
    int index=0;
};
#endif //A_STAR_PERSONAGGIO_H
