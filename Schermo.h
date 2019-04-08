//
// Created by cosimo on 04/04/19.
//

#ifndef A_STAR_WINDOW_H
#define A_STAR_WINDOW_H
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

using namespace sf;

class Schermo {
public:
    Schermo();

    ~Schermo();

    void generateScreen();
    void Astar();


private:
    Time times;
    Clock clock;
    View view;
    bool done;

    sf::Event event;

    sf::RenderWindow window;

    int h,w;


};


#endif //A_STAR_WINDOW_H
