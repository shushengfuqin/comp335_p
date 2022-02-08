//
// Created by Massimo Lopez on 2022-02-04.
//

#ifndef COMP335_P_MAP_H
#define COMP335_P_MAP_H

using namespace std;

class Territory {
public:
    const string &getName() const;

    int getId() const;

    void setName(const string &name);

    Territory(const string &name, const int &id);

private:
    string _name;
    int _id;
};

class Map {
public:
//    Map(const vector<Territory> &territory);
    Map(const int V);

    void setTerritoryVector(const vector<Territory> &territory, int rowIndex);

    void addTerritory(Territory territory, int rowIndex);

    const vector<Territory> &getTerritoryRow(int rowIndex) const;

    void printBorders(int rowIndex);

    virtual ~Map();

private:
//    const int _V;
    vector<Territory> *territory;
};

class MapLoader {
public:
    MapLoader(const string &fileName);

    const string &getContinents() const;

    const string &getCountries() const;

    const string &getBorders() const;

private:
    string continents;
    string countries;
    string borders;
};

#endif //COMP335_P_MAP_H
