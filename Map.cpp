//
// Created by Massimo Lopez on 2022-02-04.
//

#include <iostream>
#include "Map.h"

// Functions for the Territory class
const string &Territory::getName() const {
    return _name;
}

void Territory::setName(const string &name) {
    _name = name;
}

Territory::Territory(const string &name) : _name(name) {}

// Functions for the Map class
Map::Map(Territory *territory) : territory(territory) {}

Map::~Map() {
    delete territory;
    territory = NULL;
    cout << "Map is destroyed" << endl;
}

Territory *Map::getTerritory() const {
    return territory;
}

void Map::setTerritory(Territory *territory) {
    Map::territory = territory;
}
