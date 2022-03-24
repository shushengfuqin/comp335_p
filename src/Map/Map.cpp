//
// Created by Massimo Lopez on 2022-02-04.
//

#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <sstream>
#include <memory>
#include "Map.h"

// Functions for the Territory class
const string &Territory::getName() const {
    return *_name;
}

void Territory::setName(const string &name) {
    *_name = name;
}

void Territory::setContinentId(int continentId) {
    _continentId = continentId;
}

Territory::Territory(const string name, const int territoryId, const int continentId, const int numArmies) :
        _territoryId(territoryId),
        _continentId(continentId),
        _numOfArmy(numArmies) {
    _name = new string;
    *_name = name;

    _continentName = new string;
    belongToPlayer = -1;
}

void Territory::setPlayer(int playerId) {
    belongToPlayer = playerId;
}

int Territory::getPlayer() const {
    return belongToPlayer;
}

void Territory::neutralState() {
    belongToPlayer = -1;
}


int Territory::getTerritoryId() const {
    return _territoryId;
}

int Territory::getContinentId() const {
    return _continentId;
}

void Territory::setContinentName(const string &continentName) {
    *_continentName = continentName;
}

void Territory::setArmyBonusValue(int numArmies) {
    _armyBonusValue = numArmies;
}

const string &Territory::getContinentName() const {
    return *_continentName;
}

int Territory::getArmyBonusValue() const {
    return _armyBonusValue;
}

// Territory copy constructor
Territory::Territory(const Territory &t1) {
    _name = t1._name;
    _territoryId = t1._territoryId;
    _continentName = t1._continentName;
    _continentId = t1._continentId;
    _armyBonusValue = t1._armyBonusValue;
    _numOfArmy = t1._numOfArmy;
}

//Territory::~Territory() {
//    delete _name;
//    delete _continentName;
//}

// Territory Assignment Operator
Territory &Territory::operator=(const Territory &t1) {
    this->_name = t1._name;
    this->_territoryId = t1._territoryId;
    this->_continentName = t1._continentName;
    this->_continentId = t1._continentId;
    this->_armyBonusValue = t1._armyBonusValue;
    this->_numOfArmy = t1._numOfArmy;
    return *this;
}

//Territory stream insertion
std::ostream &operator<<(ostream &os, const Territory &territory) {
    os << "Hi I am a Territory" << endl;
    return os;
}

int Territory::getNumArmies() const {
    return _numOfArmy;
}

void Territory::setNumArmies(int numArmies) {
    _numOfArmy = numArmies;
}

// Functions for the Map class
// Constructor with no vector (Vector is empty)
Map::Map(const int V) : SIZE(V) {
    territory = new vector<Territory>[V];
}

// Map copy constructor
// it should call the copy constructor of the other classes
// to avoid copy the pointer
Map::Map(const Map &map1) {
    SIZE = map1.SIZE;
    territory = map1.territory;
}


// Map assignment operator overload
// it should call the copy constructor of the other classes
// to avoid copy the pointer
Map &Map::operator=(const Map &map1) {
    SIZE = map1.SIZE;
    territory = map1.territory;
    return *this;
}


//Map stream insertion
std::ostream &operator<<(ostream &os, const Map &map) {
    os << "Hi I am a Map" << endl;
    return os;
}

const int Map::getSize() const {
    return SIZE;
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
}

// Prints out the borders of the given country with that rowIndex (Adjacency list).
void Map::printTerritoryBorders(int rowIndex) {
    int territoryID = rowIndex + 1;
    cout << "Borders of Territory with id of ... " << territoryID << endl;
    for (auto neighbour: territory[rowIndex]) {
        if (neighbour.getTerritoryId() == territoryID) {
            cout << neighbour.getName()
                 << " "
                 << neighbour.getTerritoryId()
                 << " "
                 << neighbour.getContinentId()
                 << " "
                 << neighbour.getContinentName()
                 << " "
                 << neighbour.getArmyBonusValue();
            continue;
        }
        cout << " ---> " << neighbour.getName()
             << " "
             << neighbour.getTerritoryId()
             << " "
             << neighbour.getContinentId()
             << " "
             << neighbour.getContinentName()
             << " "
             << neighbour.getArmyBonusValue();
    }
    cout << endl << endl;
}

void Map::printTerritoriesByContinentId(int continentId) {
    cout << "---Countries with continent Id of " << continentId << "---" << endl;
    for (int index = 0; index < SIZE; ++index) {
        if (territory[index][0].getContinentId() == continentId) {
            cout << territory[index][0].getName() << endl;
        }
    }
}

// Moves through from a starting node to other nodes using Breath first Search
bool Map::bfs(int startIndex) {

    unique_ptr<bool[]> visited(new bool[SIZE]);
//    bool * visited = new bool[SIZE];

    queue<int> queueTerritoryIds;

    queueTerritoryIds.push(startIndex);
    visited[startIndex] = false;

    while (!queueTerritoryIds.empty()) {

        int node = queueTerritoryIds.front();

        cout << node + 1 << " ";

        vector<Territory> childList = territory[node];
        childList.erase(childList.cbegin());

        for (auto child: childList) {
            if (visited[child.getTerritoryId() - 1]) {
                queueTerritoryIds.push(child.getTerritoryId() - 1);
                visited[child.getTerritoryId() - 1] = false;
            }
        }

        queueTerritoryIds.pop();
    }

    cout << endl;

    for (int i = 0; i < (sizeof(visited) / sizeof(visited[0])); ++i) {
        if (visited[i]) {
            return false;
        }
    }
    return true;
}

bool Map::bfsContinents(int startIndex, int continentId) {

    // Set the visited array according to the number of nodes with unique continent ids
    int continentSize = 0;
    int offsetSize = 0;
    for (int i = 0; i < SIZE; ++i) {
        if (territory[i][0].getContinentId() < continentId) {
            offsetSize++;
            continue;
        }
        if (territory[i][0].getContinentId() == continentId) {
            continentSize++;
        } else {
            break;
        }
    }

    unique_ptr<bool[]> visited(new bool[SIZE]);
    for (int i = 0; i < sizeof(visited) / sizeof(visited[0]); ++i) {
        if (i < offsetSize || i >= (continentSize + offsetSize)) {
            visited[i] = false;
        }
    }

    queue<int> queueTerritoryIds;

    queueTerritoryIds.push(startIndex);
    visited[startIndex] = false;

    cout << "continent ID (" << continentId << "): ";

    while (!queueTerritoryIds.empty()) {

        int node = queueTerritoryIds.front();

        cout << node + 1 << " ";

        vector<Territory> childList = territory[node];
        childList.erase(childList.cbegin());

        for (auto child: childList) {
            if (visited[child.getTerritoryId() - 1] && child.getContinentId() == continentId) {
                queueTerritoryIds.push(child.getTerritoryId() - 1);
                visited[child.getTerritoryId() - 1] = false;
            }
        }

        queueTerritoryIds.pop();
    }
    cout << endl;

    for (int i = 0; i < (sizeof(visited) / sizeof(visited[0])); ++i) {
        if (visited[i]) {
            return false;
        }
    }
    return true;
}

// Validate the map
bool Map::validate() {

    // 1) the map is a connected graph
    for (int i = 0; i < SIZE; ++i) {
        if (!bfs(i)) {
            cout << "Fails: Map is not a connected Graph." << endl;
            return false;
        }
    }
    cout << "Passes: Map is a connected Graph." << endl;

    // 2) continents are connected subgraphs
    for (int i = 0; i < SIZE; ++i) {
        if (!bfsContinents(i, territory[i][0].getContinentId())) {
            cout << "Fails: Continents are not connected subgraphs." << endl;
            return false;
        }
    }
    cout << "Passes: Continents are connected subgraphs." << endl;

    // 3) each country belongs to one and only one continent
    for (int i = 0; i < territory->size(); ++i) {
        for (int j = 0; j < territory[i].size(); ++j) {
            for (int k = 0; k < territory->size(); k++) {
                if (territory[k][0].getTerritoryId() == territory[i][j].getTerritoryId() &&
                    territory[k][0].getContinentId() != territory[i][j].getContinentId()) {
                    cout << "Fails: A country has more than one continent." << endl;
                    return false;
                }
            }
        }
    }
    cout << "Passes: Each country belongs to one continent." << endl;

    return true;
}

vector<Territory> *Map::getTerritory() {
    return territory;
}

int Map::getNumOfTerritoriesInContinent(int id) {
    int numOfTerritories = 0;
    for (int index = 0; index < SIZE; ++index) {
        if (territory[index][0].getContinentId() == id) {
            numOfTerritories++;
        }
    }
    return numOfTerritories;
}

int Map::getLastContinentId() {
    Territory lastTerritory = territory[SIZE - 1][0];
    return lastTerritory.getContinentId();
}

int Map::getArmyContinentBonus(int continentId) {
    for (int index = 0; index < SIZE; ++index) {
        if (territory[index][0].getContinentId() == continentId) {
            return territory[index][0].getArmyBonusValue();
        }
    }
    return 0;
}
/**
 * Use a vector of pointer players, then divide the territories to each player
 * Each player should start with at least 3 countries from the same continent or as defined from the territoryLimitPerPlayer
 * @param players
 */
void Map::assignTerritoriesToPlayers(vector<Player*> players) {
    int numOfPlayers = players.size();
    int territoryLimitPerPlayer = 2; // Change this to set num of territories for each player
    int numOfTerritoriesAssignedAtPlayer = 0;
    int continentIdInQuestion = 1;
//// DEBUG: Print out size of the players
    cout << "Number of players passed in assignTerritoriesToPlayers function: " << numOfPlayers << endl;
    for (int i = 0; i < SIZE; ++i) {
        if (numOfTerritoriesAssignedAtPlayer >= territoryLimitPerPlayer) {
            if (continentIdInQuestion == territory[i][0].getContinentId()) {
                continue;
            } else {
                continentIdInQuestion++;
                numOfTerritoriesAssignedAtPlayer = 0;
            }
        }
        for (int playerIndex = 0; playerIndex < numOfPlayers; ++playerIndex) {
            if (playerIndex + 1 == territory[i][0].getContinentId() && numOfTerritoriesAssignedAtPlayer < territoryLimitPerPlayer) {
                players.at(playerIndex)->addTerritory(&territory[i][0]);
                numOfTerritoriesAssignedAtPlayer++;
            }
        }
    }
}


// Functions for the MapLoader
MapLoader::MapLoader(const string &fileName) {
    continents = new string;
    countries = new string;
    borders = new string;

    ifstream inputFileStream(fileName);

    string validExtension = ".map";
    // Checks if the file is really of .map type
    if (fileName.find(validExtension) != string::npos) {
        cout << "This is a .map file" << endl;
    } else {
        cout << "This is not a valid .map file" << endl;
    }
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
        if (inContinents && line.length() != 0) {
            *continents += line + "\n";
        }
        // Reading Countries
        if (inCountries && line.length() != 0) {
            *countries += line + "\n";
        }
        // Reading Borders
        if (inBorders && line.length() != 0) {
            *borders += line + "\n";
        }

    }
    inputFileStream.close();
}


// Copy constructor
MapLoader::MapLoader(const MapLoader &mapLoader1) {
    continents = mapLoader1.continents;
    countries = mapLoader1.countries;
    borders = mapLoader1.borders;
}

// Creates a map object as a graph data structure.
Map *MapLoader::generateMap() {
    istringstream issCountry(*countries);
    istringstream issBorder(*borders);
    // Count the lines in the continents.
    int lineCountryCount = 0;
    int lineBordersCount = 0;
    for (string line; getline(issCountry, line);) {
        lineCountryCount++;
    }
    for (string line; getline(issBorder, line);) {
        lineBordersCount++;
    }
    if (lineCountryCount != lineBordersCount) {
        cout << "This map cannot be generate because the file is not valid. "
             << endl
             << "Map value is set to NULL." << endl;
        return NULL;
    }

    Map *map = new Map(lineBordersCount - 1); // -1 so as to not count the last line (\n)
    this->map = map;

    // Clear and reset the StringStreams
    issCountry.str("");
    issBorder.str("");
    issCountry.clear();
    issBorder.clear();
    issCountry.str(*countries);
    issBorder.str(*borders);

    string lineBorder;
    string lineCountry;
    int lineIndex = 0;
    string spaceDelimiter = " ";

    // Loop through both country and borders string strings
    for (; getline(issCountry, lineCountry), getline(issBorder, lineBorder);) {
        string spaceDelimiter = " ";

        // Vector for all the info about each country
        vector<string> countryValues{};
        size_t pos = 0;
        while ((pos = lineCountry.find(spaceDelimiter)) != string::npos) {
            countryValues.push_back(lineCountry.substr(0, pos));
            lineCountry.erase(0, pos + spaceDelimiter.length());
        }
        countryValues.push_back(lineCountry.substr(0, pos));
        lineCountry.erase(0, pos + spaceDelimiter.length());

        // Vector for all the info about each country's borders
        vector<string> borderValues{};
        pos = 0;
        while ((pos = lineBorder.find(spaceDelimiter)) != string::npos) {
            borderValues.push_back(lineBorder.substr(0, pos));
            lineBorder.erase(0, pos + spaceDelimiter.length());
        }
        borderValues.push_back(lineBorder.substr(0, pos));
        lineBorder.erase(0, pos + spaceDelimiter.length());

        // Generate the Nodes of each territory
        if (lineIndex > 0) { // First line is the title for the whole string
            int territoryId = stoi(countryValues[0]);
            string territoryName = countryValues[1];
            int continentId = stoi(countryValues[2]);
            Territory *territory = new Territory(territoryName, territoryId, continentId, 0);

            // Add a territory as Node in vector list
            map->addTerritory(*territory, lineIndex - 1);

            // Add adjacent Nodes
            for (int i = 1; i < borderValues.size(); i++) {
                if (borderValues[i] == "") {
                    continue;
                }
                int adjTerritoryId = stoi(borderValues[i]);

                Territory *adjTerritory = new Territory("", adjTerritoryId, -1, 0);
                map->addTerritory(*adjTerritory, lineIndex - 1);

                delete (adjTerritory);
                adjTerritory = NULL;
            }

            // delete the territory when done.
            delete (territory);
            territory = NULL;
        }

        lineIndex++;
    }

    // Update Adjacent Territories
    string adjTerritoryName;
    int adjContinentId;

    // Find the territory's name and continent id base on territory id
    for (int i = 0; i < map->getSize(); i++) {
        for (int j = 1; j < map->getTerritoryRow(i).size(); j++) {
            for (int k = 0; k < map->getSize(); k++) {
                if (map->getTerritory()[k][0].getTerritoryId() == map->getTerritory()[i][j].getTerritoryId()) {
                    adjTerritoryName = (map->getTerritory())[k][0].getName();
                    adjContinentId = (map->getTerritory())[k][0].getContinentId();
                    map->getTerritory()[i][j].setName(adjTerritoryName);
                    map->getTerritory()[i][j].setContinentId(adjContinentId);
                    break;
                }
            }
        }
    }

    // Need to set the continent Names and number of continents
    istringstream issContinents(*continents);
    int continentIndex = 0;
    for (string lineContinents; getline(issContinents, lineContinents);) {
        string spaceDelimiter = " ";

        // Vector for all the info about each continent
        vector<string> continentValues{};
        size_t pos = 0;
        while ((pos = lineContinents.find(spaceDelimiter)) != string::npos) {
            continentValues.push_back(lineContinents.substr(0, pos));
            lineContinents.erase(0, pos + spaceDelimiter.length());
        }
        continentValues.push_back(lineContinents.substr(0, pos));
        lineContinents.erase(0, pos + spaceDelimiter.length());

        if (continentIndex > 0) { // first line is the name contintents
            string continentName;
            int numArmies;
            for (int i = 0; i < map->getSize(); i++) {
                for (int j = 0; j < map->getTerritoryRow(i).size(); j++) {
                    if (map->getTerritory()[i][j].getContinentId() == continentIndex) {
                        continentName = continentValues[0];
                        numArmies = stoi(continentValues[1]);
                        map->getTerritory()[i][j].setContinentName(continentName);
                        map->getTerritory()[i][j].setArmyBonusValue(numArmies);
                    }
                }
            }
        }
        continentIndex++;
    }


    return map;
}

MapLoader &MapLoader::operator=(const MapLoader &mapLoader1) {
    map = mapLoader1.map;
    continents = mapLoader1.continents;
    countries = mapLoader1.countries;
    borders = mapLoader1.borders;
    return *this;
}

std::ostream &operator<<(ostream &os, const MapLoader &mapLoader1) {
    os << "Hi I am a MapLoader" << endl;
    return os;
}


MapLoader::~MapLoader() {
    delete (map);
    map = NULL;
    delete (continents);
    continents = NULL;
    delete (countries);
    countries = NULL;
    delete (borders);
    borders = NULL;

}


/**
 * Given a territory called source, and a destination territory target, find if it its possible to move from source to target
 * @param source
 * @param target
 * @return
 */
bool Map::isAdjacentTerritory(Territory *source, Territory *target) {
    for (int i = 0; i < SIZE; ++i) {
        if (territory[i][0].getTerritoryId() == source->getTerritoryId()) {
            for (auto adjTerritory: territory[i]) {
                if (adjTerritory.getTerritoryId() == target->getTerritoryId()) {
                    return true;
                }
            }
        }
    }
    return false;
}

/**
 * Find all adjacent territories of a territory. Pass in the territory, and find the vector list of the adjacent territories by the territory id.
 * @param territory
 * @return getterritoryRow
 */
vector<Territory*> Map::getAllAdjacentTerritories(Territory territory) {
    int territoryId = territory.getTerritoryId();
    vector<Territory*> adjTerritories;

    for (int i = 0; i < SIZE; ++i) {
        if (this->territory[i][0].getTerritoryId() == territoryId) {
            for (auto  &terr: this->territory[i]){
                cout << "Debug " << terr;
                adjTerritories.push_back(&terr);
            }
            adjTerritories.erase(adjTerritories.begin());
            return adjTerritories;
        }
    }
}
