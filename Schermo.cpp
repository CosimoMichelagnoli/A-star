//
// Created by cosimo on 04/04/19.
//

#include <iostream>
#include "Schermo.h"
#include "Mappa.h"
#include "Personaggio.h"
#include "MapSearchNode.h"
#include "Target.h"
//#include "Graphic.h"
#define TILE 80

using namespace std;
using namespace sf;

Schermo::Schermo() {

    Mappa::Instance(1)->load();
    view.setSize(Mappa::Instance()->getWidth()*TILE,Mappa::Instance()->getHeight()*TILE);
    view.setCenter(Mappa::Instance()->getWidth()*TILE/2,Mappa::Instance()->getHeight()*TILE/2);
    int goalx,startx;
    int goaly, starty;
    done=false;
    do{
        startx= static_cast<int>(random() % Mappa::Instance()->getHeight());
        starty= static_cast<int>(random()%Mappa::Instance()->getWidth());
         goalx= static_cast<int>(random() % Mappa::Instance()->getHeight());
         goaly= static_cast<int>(random()%Mappa::Instance()->getWidth());
    }
    while (((Mappa::Instance()->getLvlmap())[goalx*(Mappa::Instance()->getWidth())+goaly]!=9)&&(Mappa::Instance()->getLvlmap())[(startx*(Mappa::Instance()->getWidth()))+starty]!=9);
    Personaggio::Instance()->setPos(startx*TILE,starty*TILE);
    Target::Instance()->setpos(goalx*TILE,goaly*TILE);
    window.create(sf::VideoMode(800,600), "A*-algoritm");
    window.setFramerateLimit(60);
    sf::WindowHandle handle = window.getSystemHandle();
    sf::Window window(handle);

}

void Schermo::generateScreen() {


    while (window.isOpen()) {

            while (window.pollEvent(event)) {

                if (event.type == sf::Event::Closed)
                    window.close();
            }
            window.setView(view);

            window.setActive();

            window.clear();


            Mappa::Instance()->drawMap(window);
            Target::Instance()->drawPersonaggio(window);
            Astar();

            times=clock.getElapsedTime();
            if(times.asSeconds()>1){
                Personaggio::Instance()->setPos();
                clock.restart();
            }

            Personaggio::Instance()->drawPersonaggio(window);
            done=true;
            window.display();
    }
}

void Schermo::Astar() {
    if(!done){
    AStarSearch<MapSearchNode> astarsearch;

    unsigned int SearchCount = 0;

    const unsigned int NumSearches = 1;

    while (SearchCount < NumSearches) {

        // Create a start state
        MapSearchNode nodeStart;
        nodeStart.x = Personaggio::Instance()->getX() / TILE;
        nodeStart.y = Personaggio::Instance()->getY() / TILE;
        cout << "Punto di partenza (" << nodeStart.x << "," << nodeStart.y << ")" << endl;

        // Define the goal state
        MapSearchNode nodeEnd;
        nodeEnd.x = Target::Instance()->getX() / TILE;
        nodeEnd.y = Target::Instance()->getY() / TILE;
        cout << "Punto di arrivo (" << nodeEnd.x << "," << nodeEnd.y << ")" << endl;

        // Set Start and goal states

        astarsearch.SetStartAndGoalStates(nodeStart, nodeEnd);

        unsigned int SearchState;
        unsigned int SearchSteps = 0;

        do {
            SearchState = astarsearch.SearchStep();

            SearchSteps++;

#if DEBUG_LISTS

            cout << "Steps:" << SearchSteps << "\n";

                int len = 0;

                cout << "Open:\n";
                MapSearchNode *p = astarsearch.GetOpenListStart();
                while( p )
                {
                    len++;
#if !DEBUG_LIST_LENGTHS_ONLY
                    ((MapSearchNode *)p)->PrintNodeInfo();
#endif
                    p = astarsearch.GetOpenListNext();

                }

                cout << "Open list has " << len << " nodes\n";

                len = 0;

                cout << "Closed:\n";
                p = astarsearch.GetClosedListStart();
                while( p )
                {
                    len++;
#if !DEBUG_LIST_LENGTHS_ONLY
                    p->PrintNodeInfo();
#endif
                    p = astarsearch.GetClosedListNext();
                }

                cout << "Closed list has " << len << " nodes\n";
#endif

        } while (SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SEARCHING);

        if (SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SUCCEEDED) {
            cout << "Search found goal state\n";

            MapSearchNode *node = astarsearch.GetSolutionStart();

#if DISPLAY_SOLUTION
            cout << "Displaying solution\n";
#endif
            int steps = 0;

            node->PrintNodeInfo();
            //Personaggio::Instance()->drawPersonaggio(window);
            //Mappa::Instance()->mostraMappa();
            for (;;) {
                node = astarsearch.GetSolutionNext();



                if (!node) {
                    break;
                }


                node->PrintNodeInfo();
                //Personaggio::Instance()->drawPersonaggio(window);
                //Mappa::Instance()->mostraMappa();
                steps++;



            };

            cout << "Solution steps " << steps << endl;

            // Once you're done with the solution you can free the nodes up
            astarsearch.FreeSolutionNodes();


        } else if (SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_FAILED) {
            cout << "Search terminated. Did not find goal state\n";

        }

        // Display the number of loops the search went through
        cout << "SearchSteps : " << SearchSteps << "\n";

        SearchCount++;

        astarsearch.EnsureMemoryFreed();
    }

}
}

Schermo::~Schermo() = default;