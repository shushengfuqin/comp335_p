//
// Created by Massimo Lopez on 2022-02-04.
//

#ifndef COMP335_P_TERRITORY_H
#define COMP335_P_TERRITORY_H

#include <iostream>

using namespace std;

class Territory {
public:
    const string &getName() const;

    void setName(const string &name);

    Territory(const string &name);

private:
    string _name;
};


#endif //COMP335_P_TERRITORY_H
