//
// Created by cosimo on 26/03/19.
//

#ifndef A_STAR_PERSONAGGIO_H
#define A_STAR_PERSONAGGIO_H


class Personaggio {
public:
    ~Personaggio();

    int getX() const;

    void setX(int x);

    int getY() const;

    void setY(int y);


    static Personaggio *Instance();


protected:
    Personaggio();

private:
    static Personaggio* instance;
    int x;
    int y;
};
#endif //A_STAR_PERSONAGGIO_H
