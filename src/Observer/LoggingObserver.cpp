//
// Created by Gin on 2022-03-01.
//

#include <iostream>
#include <vector>
#include <fstream>
#include "LoggingObserver.h"

using namespace std;

void Subject::Attach(Observer *obs) {
    _observers->push_back(obs);
}

void Subject::Detach (Observer* obs)
{
    int count = _observers->size();
    int i;

    for (i = 0; i < count; i++) {
        if(_observers[i] == obs)
            break;
    }
    if(i < count)
        _observers->erase(_observers->begin() + i);

}
Subject::Subject() = default;

void Subject::Notify ()
{
    int count = _observers->size();

    for (int i = 0; i < count; i++)
        (_observers[i]).Update(this);
}

void LogObserver::writeToFile(string s) {
    cout << "hello";
    ofstream myfile;
    myfile.open ("example.txt");
    myfile << s;
    myfile.close();
}

LogObserver::LogObserver() = default;

LogObserver::~LogObserver() = default;

ILoggable::ILoggable() = default;

ILoggable::~ILoggable() = default;

Observer::Observer() = default;

Observer::~Observer() = default;
