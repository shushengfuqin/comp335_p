//
// Created by Massimo Lopez on 2022-02-04.
//

#include <iostream>
#include <vector>
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
Map::Map(const vector<Territory> &territory) : territory(territory) {}

void Map::setTerritory(const vector<Territory> &territory) {
    Map::territory = territory;
}

const vector<Territory> &Map::getTerritory() const {
    return territory;
}

Map::~Map() {
    territory.clear();
}
