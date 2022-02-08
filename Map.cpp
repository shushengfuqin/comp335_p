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

Territory::Territory(const string &name, const int &id) : _name(name), _id(id) {}

int Territory::getId() const {
    return _id;
}


// Functions for the Map class
// Constructor with vector of territories
//Map::Map(const vector<Territory> &territory) : territory(territory) {}
// Constructor with no vector (Vector is empty)
Map::Map(const int V) {
//    for (int i = 0; i < V; i++) {
//        territory.push_back(vector<Territory>());
//    }
    territory = new vector<Territory>[V];
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
    delete[] territory;
    territory = NULL;

//    delete[] territory;
//    territory = NULL;
}

// Prints out the borders of the given country with that rowIndex (Adjacency list).
void Map::printBorders(int rowIndex) {
    int id = rowIndex + 1;
    cout << "Borders of Territory with id of ... " << id << endl;
    for (auto neighbour: territory[rowIndex]) {
        if (neighbour.getId() == id) {
            cout << neighbour.getName();
            continue;
        }
        cout << " -> " << neighbour.getName();
    }
    cout << endl << endl;
}

MapLoader::MapLoader(const string &fileName) {
    ifstream inputFileStream(fileName);

    if (!inputFileStream) {
        cerr << "Unable to open file .map file";
        exit(1);   // call system to stop
    }

    string line;
    bool inContinents = false;
    bool inCountries = false;
    bool inBorders = false;
    while (!inputFileStream.eof()) {
        getline(inputFileStream, line);

        // Booleans to set where to copy the read values
        if (line == "[continents]") {
            inContinents = true;
        }
        if (line == "[countries]") {
            inContinents = false;
            inCountries = true;
        }
        if (line == "[borders]") {
            inCountries = false;
            inBorders = true;
        }

        // Reading Continents
        if (inContinents) {
            continents += line + "\n";
        }
        // Reading Countries
        if (inCountries) {
            countries += line + "\n";
        }
        // Reading Borders
        if (inBorders) {
            borders += line + "\n";
        }

    }
    inputFileStream.close();
}

const string &MapLoader::getContinents() const {
    return continents;
}

const string &MapLoader::getCountries() const {
    return countries;
}

const string &MapLoader::getBorders() const {
    return borders;
}
