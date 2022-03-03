//
// Created by Gin on 2022-03-01.
//

#include <iostream>
#include <list>
#include <fstream>
#include "LoggingObserver.h"

using namespace std;

void Subject::Attach(Observer *obs) {
    _observers->push_back(obs);
}

void Subject::Detach(Observer *obs) {
    _observers->remove(obs);
}

//void Subject::Notify(ILoggable) {
//    ListIterator<Observer*> i(_observers);
//}

LogObserver::LogObserver() = default;

void LogObserver::writeToFile(string s) {
    ofstream myfile;
    myfile.open ("example.txt");
    myfile << "Writing this to a file.\n";
    myfile.close();
}
