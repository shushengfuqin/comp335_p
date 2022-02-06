//
// Created by Massimo Lopez on 2022-02-04.
//

#ifndef COMP335_P_MAP_H
#define COMP335_P_MAP_H

using namespace std;

class Territory {
public:
    const string &getName() const;
    void setName(const string &name);
    Territory(const string &name);

private:
    string _name;
};

class Map {
public:
    Map(const vector<Territory> &territory);
    Map();
    void setTerritoryVector(const vector<Territory> &territory);
    void addTerritory(Territory territory);
    const vector<Territory> &getTerritory() const;
    virtual ~Map();

private:
    vector<Territory> territory;
};


#endif //COMP335_P_MAP_H
