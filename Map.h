//
// Created by Massimo Lopez on 2022-02-04.
//

#ifndef COMP335_P_MAP_H
#define COMP335_P_MAP_H

#include "Territory.h"
using namespace std;

class Map {
public:
    Map(Territory *territory);

    Territory *getTerritory() const;

    void setTerritory(Territory *territory);

    virtual ~Map();


private:
    Territory* territory;
};


#endif //COMP335_P_MAP_H
