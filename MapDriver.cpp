//
// Created by Massimo Lopez on 2022-02-04.
//

#include <iostream>
#include <vector>
#include "Map.h"

int main() {
    Territory *territory1 = new Territory("USA");
    Territory *territory2 = new Territory("Canada");

    std::vector<Territory> myTerritories;
    myTerritories.push_back(*territory1);
    myTerritories.push_back(*territory2);
    Map *map = new Map(myTerritories);
    cout << "Hello " << map->getTerritory().at(0).getName() << endl;
    cout << "Hello " << map->getTerritory().at(1).getName() << endl;

    delete (map);
    map = NULL;
    return 0;
}