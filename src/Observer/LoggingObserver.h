//
// Created by Gin on 2022-03-06.
//

#ifndef COMP335_P_LOGGINGOBSERVER_H
#define COMP335_P_LOGGINGOBSERVER_H

#include <iostream>
#include <fstream>
#include <list>
#pragma once

using namespace std;
class ILoggable;
class LogObserver;
class Observer;

class Subject{
public:
    Subject();
    ~Subject();

    void Detach(Observer *obs);
    void Notify(ILoggable* il);

    void Attach(Observer *obs);

private:
    list<Observer *> _observers;
};

class Observer{
public:
    Observer();
    ~Observer();
    virtual void Update(ILoggable* il) = 0;
};

class ILoggable{
public:
    ILoggable();
    ~ILoggable();
    virtual string stringToLog() = 0;

};

class LogObserver: public Observer{
public:
    LogObserver();
    LogObserver(Subject* s);
    ~LogObserver();
    void Update(ILoggable* il) override;

protected:
    Subject* _subjects;
};

#endif //COMP335_P_LOGGINGOBSERVER_H
