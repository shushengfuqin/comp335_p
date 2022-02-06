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
// Constructor with vector of territories
Map::Map(const vector<Territory> &territory) : territory(territory) {}
// Constructor with no vector (Vector is empty)
Map::Map(){}

// set the vector
void Map::setTerritoryVector(const vector<Territory> &territory) {
    Map::territory = territory;
}

// Add a pointer to a territory (new Territory).
void Map::addTerritory(Territory territory) {
//    this->territory.push_back(territory);
    this->territory.push_back(territory);
}

// Return a vector of territories
const vector<Territory> &Map::getTerritory() const {
    return territory;
}

// Erase the vector
Map::~Map() {
    territory.clear();
}
