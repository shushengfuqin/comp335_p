//
// Created by Massimo Lopez on 2022-02-04.
//

#include <iostream>
#include "Map.h"

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
