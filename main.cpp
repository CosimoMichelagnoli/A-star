#include <iostream>
#include "Mappa.h"
#include <iostream>
using namespace std;
int main() {
    Mappa map;
    map.setMappa();
    for(int i=0; i<3;i++){
        for(int j=0;j<3;j++){
            cout<<map.getTileValue(i,j)<<"  ";
        }cout<<endl;
    }cout<<endl;
    for(int i=0; i<3;i++){
        for(int j=0;j<3;j++){
            cout<<map.getTileWall(i,j)<<"  ";
        }cout<<endl;
    }

}