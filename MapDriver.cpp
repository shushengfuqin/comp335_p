//
// Created by Massimo Lopez on 2022-02-04.
//

#include <iostream>
#include <vector>
#include "Map.h"

int main() {

    Map *map = new Map(); // Create a new map
    Territory *t1 = new Territory("USA");
    Territory *t2 = new Territory("Canada");
    map->addTerritory(*t1); // Push territory to vector
    map->addTerritory(*t2);
    cout << "Hello " << map->getTerritory().at(0).getName() << endl;
    cout << "Hello " << map->getTerritory().at(1).getName() << endl;

    delete (map); // delete values of map on heap
    map = NULL; // erase the address of the map.

    delete (t1); // delete values of territory1 on heap
    t1 = NULL; // erase the address of the territory1.

    delete (t2); // delete values of territory2 on heap
    t2 = NULL; // erase the address of the territory2.
    return 0;
}