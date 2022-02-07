//
// Created by Massimo Lopez on 2022-02-04.
//

#include <iostream>
#include <vector>
#include "Map.h"

const int SIZE = 13;

int main() {

    // For now, manually making an example map (Based from the assignment video)
    Map *map = new Map(SIZE); // new map
    Territory *t1 = new Territory("1"); // new territories
    Territory *t2 = new Territory("2");
    Territory *t3 = new Territory("3");
    Territory *t4 = new Territory("4");
    Territory *t5 = new Territory("5");
    Territory *t6 = new Territory("6");
    Territory *t7 = new Territory("7");
    Territory *t8 = new Territory("8");
    Territory *t9 = new Territory("9");
    Territory *t10 = new Territory("10");
    Territory *t11 = new Territory("11");
    Territory *t12 = new Territory("12");
    Territory *t13 = new Territory("13");

//    Territory *territoryList[] = {t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13};

    // Manually assigning their adjacency territories (borders)
    // Adjacent to "1"
//    map->addTerritory(*t1, 0);
    map->addTerritory(*t2, 0); // Push territory to vector
    map->addTerritory(*t3, 0);

    // Adjacent to "2"
//    map->addTerritory(*t2, 1);
    map->addTerritory(*t1, 1);
    map->addTerritory(*t3, 1);

    // Adjacent to "3"
//    map->addTerritory(*t3, 2);
    map->addTerritory(*t1, 2);
    map->addTerritory(*t2, 2);
    map->addTerritory(*t13, 2);

    // Adjacent to "4"
//    map->addTerritory(*t4, 3);
    map->addTerritory(*t5, 3);

    // Adjacent to "5"
//    map->addTerritory(*t5, 4);
    map->addTerritory(*t13, 4);

    // Adjacent to "6"
//    map->addTerritory(*t6, 5);
    map->addTerritory(*t7, 5);

    // Adjacent to "7"
//    map->addTerritory(*t7, 6);
    map->addTerritory(*t13, 6);
    map->addTerritory(*t8, 6);

    // Adjacent to "8"
//    map->addTerritory(*t8, 7);
    map->addTerritory(*t6, 7);

    // Adjacent to "9"
//    map->addTerritory(*t9, 8);
    map->addTerritory(*t10, 8);

    // Adjacent to "10"
//    map->addTerritory(*t10, 9);
    map->addTerritory(*t12, 9);

    // Adjacent to "11"
//    map->addTerritory(*t11, 10);
    map->addTerritory(*t13, 10);

    // Adjacent to "12"
//    map->addTerritory(*t12, 11);
    map->addTerritory(*t11, 11);

    // Adjacent to "13"
//    map->addTerritory(*t13, 12);
    map->addTerritory(*t4, 12);
    map->addTerritory(*t3, 12);
    map->addTerritory(*t9, 12);
    map->addTerritory(*t7, 12);

    for (int i = 0; i < SIZE; i++) {
        map->printBorders(i);
        cout << "Max size (row " << i << ") = "
             << map->getTerritoryRow(i).max_size() - map->getTerritoryRow(i).size()
             << endl  << endl;
    }

    delete (map); // delete values of map on heap
    map = NULL; // erase the address of the map.

    delete (t1); // delete values of territory1 on heap
    t1 = NULL; // erase the address of the territory1.

    delete (t2); // delete values of territory2 on heap
    t2 = NULL; // erase the address of the territory2.

    delete (t3); // delete values of territory3 on heap
    t3 = NULL; // erase the address of the territory3.

    delete (t4); // delete values of territory4 on heap
    t4 = NULL; // erase the address of the territory4.

    delete (t5); // delete values of territory5 on heap
    t5 = NULL; // erase the address of the territory5.

    delete (t6); // delete values of territory6 on heap
    t6 = NULL; // erase the address of the territory6.

    delete (t7); // delete values of territory7 on heap
    t7 = NULL; // erase the address of the territory7.

    delete (t8); // delete values of territory8 on heap
    t8 = NULL; // erase the address of the territory8.

    delete (t9); // delete values of territory9 on heap
    t9 = NULL; // erase the address of the territory9.

    delete (t10); // delete values of territory10 on heap
    t10 = NULL; // erase the address of the territory10.

    delete (t11); // delete values of territory11 on heap
    t11 = NULL; // erase the address of the territory11.

    delete (t12); // delete values of territory12 on heap
    t12 = NULL; // erase the address of the territory12.

    delete (t13); // delete values of territory13 on heap
    t13 = NULL; // erase the address of the territory13.

    cout << "---Map Loader ---" << endl;

    MapLoader *mapLoader = new MapLoader("../canada/canada.map");
    cout << mapLoader->getDescription() << endl;

    delete (mapLoader);
    mapLoader = NULL;

    return 0;
}