//
// Created by Massimo Lopez on 2022-02-04.
//

#include <iostream>
#include <vector>
#include "Map.h"

const int SIZE = 13;

int main() {

    Map *map = new Map(SIZE); // Create a new map
    Territory *t1 = new Territory("1");
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

    // Adjacent to "1"
    map->addTerritory(*t1, 0);
    map->addTerritory(*t2, 0); // Push territory to vector
    map->addTerritory(*t3, 0);

    // Adjacent to "2"
    map->addTerritory(*t2, 1);
    map->addTerritory(*t1, 1);
    map->addTerritory(*t3, 1);

    // Adjacent to "3"
    map->addTerritory(*t3, 2);
    map->addTerritory(*t1, 2);
    map->addTerritory(*t2, 2);
    map->addTerritory(*t13, 2);

    // Adjacent to "4"
    map->addTerritory(*t4, 3);
    map->addTerritory(*t5, 3);

    // Adjacent to "5"
    map->addTerritory(*t5, 4);
    map->addTerritory(*t13, 4);

    // Adjacent to "6"
    map->addTerritory(*t6, 5);
    map->addTerritory(*t7, 5);

    // Adjacent to "7"
    map->addTerritory(*t7, 6);
    map->addTerritory(*t13, 6);
    map->addTerritory(*t8, 6);

    // Adjacent to "8"
    map->addTerritory(*t8, 7);
    map->addTerritory(*t6, 7);

    // Adjacent to "9"
    map->addTerritory(*t9, 8);
    map->addTerritory(*t10, 8);

    // Adjacent to "10"
    map->addTerritory(*t10, 9);
    map->addTerritory(*t12, 9);

    // Adjacent to "11"
    map->addTerritory(*t11, 10);
    map->addTerritory(*t13, 10);

    // Adjacent to "12"
    map->addTerritory(*t12, 11);
    map->addTerritory(*t11, 11);

    // Adjacent to "13"
    map->addTerritory(*t13, 12);
    map->addTerritory(*t4, 12);
    map->addTerritory(*t3, 12);
    map->addTerritory(*t9, 12);
    map->addTerritory(*t7, 12);

    cout << "Hello " << map->getTerritory(0)[0].getName() << endl;
    cout << "Hello " << map->getTerritory(1)[0].getName() << endl;
    cout << "Hello " << map->getTerritory(2)[0].getName() << endl;
    cout << "Hello " << map->getTerritory(3)[0].getName() << endl;
    cout << "Hello " << map->getTerritory(4)[0].getName() << endl;
    cout << "Hello " << map->getTerritory(5)[0].getName() << endl;
    cout << "Hello " << map->getTerritory(6)[0].getName() << endl;
    cout << "Hello " << map->getTerritory(7)[0].getName() << endl;
    cout << "Hello " << map->getTerritory(8)[0].getName() << endl;
    cout << "Hello " << map->getTerritory(9)[0].getName() << endl;
    cout << "Hello " << map->getTerritory(10)[0].getName() << endl;
    cout << "Hello " << map->getTerritory(11)[0].getName() << endl;
    cout << "Hello " << map->getTerritory(12)[0].getName() << endl;
//    cout << "Hello " << map->getTerritory(13)[0].getName() << endl;

    cout << "Max size (row 0) = " << map->getTerritory(0).max_size() - map->getTerritory(0).size() << endl;

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