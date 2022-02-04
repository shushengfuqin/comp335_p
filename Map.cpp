//
// Created by Massimo Lopez on 2022-02-04.
//

#include "Map.h"

Map::Map(const string &title) : title(title) {}

Map::~Map() {

}

const string &Map::getTitle() const {
    return title;
}

void Map::setTitle(const string &title) {
    Map::title = title;
}

Map::Map() {

}
