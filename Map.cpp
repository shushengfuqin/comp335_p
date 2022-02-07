//
// Created by Massimo Lopez on 2022-02-04.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
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
//Map::Map(const vector<Territory> &territory) : territory(territory) {}
// Constructor with no vector (Vector is empty)
Map::Map(const int V) {
    for (int i = 0; i < V; i++){
        territory.push_back(vector<Territory>());
    }
}

// set the vector
void Map::setTerritoryVector(const vector<Territory> &territory, int rowIndex) {
    Map::territory[rowIndex] = territory;
}

// Add a pointer to a territory (new Territory).
void Map::addTerritory(Territory territory, int rowIndex) {
//    this->territory.push_back(territory);
    this->territory[rowIndex].push_back(territory);
}

// Return a vector of territories
const vector<Territory> &Map::getTerritoryRow(int rowIndex) const {
    return territory[rowIndex];
}

// Erase the vector
Map::~Map() {
    territory.clear();
//    delete[] territory;
//    territory = NULL;
}

// Prints out the borders of the given country with that rowIndex (Adjacency list).
// TODO: Make a territory have an id and a name to lookup the borders from that index.
void Map::printBorders(int rowIndex) {
    cout << "Borders of Territory with index of ... " << rowIndex + 1 << endl;
    cout << rowIndex + 1;
    for (auto neighbour : territory[rowIndex]) {
        cout << " -> " << neighbour.getName();
    }
    cout << endl << endl;
}

MapLoader::MapLoader(const string &fileName) {
    ifstream inputFileStream(fileName);
//    cout << inputFileStream.eof() << endl;
//    inputFileStream.getline()

    if (inputFileStream) {
        ostringstream oss;
        oss << inputFileStream.rdbuf();
        description = oss.str();
    }
    inputFileStream.close();
}

const string &MapLoader::getDescription() const {
    return description;
}
