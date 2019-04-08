//
// Created by cosimo on 26/03/19.
//

#ifndef A_STAR_MAPPA_H
#define A_STAR_MAPPA_H
#include <vector>
#include <string>
#include "Tile.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Mappa {
public:
    ~Mappa();


    void drawMap(RenderWindow &window);
    static Mappa* Instance(int nmap=rand()%2);
    //int getTileValue(int x, int y);
    int getWidth() const;
    int getHeight() const;
    //bool getTileWall(int x,int y);
    int getMap(int x, int y);
    void setLvlmap(int x, int y);
    void mostraMappa();
    bool load();

    int *getLvlmap() const;

protected:
    Mappa();//per ereditare nelle classi mappa
    //explicit Mappa(string nomefile);
    int width;
    int height;
    int goalx;
    int goaly;
    //vector<vector<int>>tiles;
    vector<int>type;
    void setMappa();


private:
    RenderStates st;
    sf::VertexArray vert;
    Texture texture;
    string namefile;
    static Mappa* instance;
    int* lvlmap;
    //char* percorso;


};


#endif //A_STAR_MAPPA_H
