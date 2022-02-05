//
// Created by Massimo Lopez on 2022-02-04.
//

#include "Territory.h"

const string &Territory::getName() const {
    return _name;
}

void Territory::setName(const string &name) {
    _name = name;
}

Territory::Territory(const string &name) : _name(name) {}
