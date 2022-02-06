//
// Created by Massimo Lopez on 2022-02-04.
//

#include <iostream>
#include <vector>
#include "Map.h"

const int SIZE = 7;

int main() {

    Map *map = new Map(SIZE); // Create a new map
    Territory *t1 = new Territory("Canada");
    Territory *t2 = new Territory("USA");
    Territory *t3 = new Territory("Italy");

    map->addTerritory(*t1, 0); // Push territory to vector
    map->addTerritory(*t2, 0);
    map->addTerritory(*t3, 1);

    cout << "Hello " << map->getTerritory(0)[0].getName() << endl;
    cout << "Hello " << map->getTerritory(0)[1].getName() << endl;
    cout << "Hello " << map->getTerritory(1)[0].getName() << endl;

    delete (map); // delete values of map on heap
    map = NULL; // erase the address of the map.

    delete (t1); // delete values of territory1 on heap
    t1 = NULL; // erase the address of the territory1.

    delete (t2); // delete values of territory2 on heap
    t2 = NULL; // erase the address of the territory2.

    delete (t3); // delete values of territory3 on heap
    t3 = NULL; // erase the address of the territory3.
    return 0;
}