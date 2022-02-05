//
// Created by Massimo Lopez on 2022-02-04.
//


#include "Map.h"
#include "Territory.h"

int main(){
    Territory* territory = new Territory("USA");
    Map* map = new Map(territory);
    cout << "Hello " << map->getTerritory()->getName() << endl;

    delete(map);
    map = NULL;
    return 0;
}