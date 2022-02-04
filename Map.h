//
// Created by Massimo Lopez on 2022-02-04.
//

#ifndef COMP335_P_MAP_H
#define COMP335_P_MAP_H

#include <string>
using namespace std;

class Map {
public:
    Map();

    Map(const string &title);

    void setTitle(const string &title);

    virtual ~Map();

    const string &getTitle() const;

private:
    string title;
};


#endif //COMP335_P_MAP_H
