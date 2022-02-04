//
// Created by Massimo Lopez on 2022-02-04.
//

#include <iostream>
#include "Map.h"

using namespace std;

int main(){
    Map* map = new Map("Canada");
    Map map2;
    map2.setTitle("USA");
    cout << "Hello (map1) " << map->getTitle() << endl;
    cout << "Hello (map2) " << map2.getTitle() << endl;
    delete(map);
    map = NULL;
    return 0;
}