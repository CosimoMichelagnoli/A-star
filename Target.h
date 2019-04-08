//
// Created by cosimo on 06/04/19.
//

#ifndef A_STAR_TARGET_H
#define A_STAR_TARGET_H
#include <SFML/Graphics.hpp>
using namespace sf;

class Target {
public:
    ~Target();
    static Target *Instance();
    void drawPersonaggio(RenderWindow &window);
    int getX() const;

    void setX(int x);

    int getY() const;

    void setY(int y);
    void setpos(int x, int y);

protected:    Target();

private:
    Sprite sprite;
    Texture texture;
    static Target* instance;
    int x;
    int y;
};


#endif //A_STAR_TARGET_H
