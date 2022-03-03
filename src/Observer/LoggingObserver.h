//
// Created by Gin on 2022-03-01.
//
#include <list>
#ifndef COMP335_P_LOGGINGOBSERVER_H
#define COMP335_P_LOGGINGOBSERVER_H
#pragma once

using namespace std;
class ILoggable;
class LogObserver;
class Observer;

class Subject{
public:
    void Attach(Observer *obs);
    void Detach(Observer *obs);
    void Notify(ILoggable);

protected:
    Subject();

private:
    list<Observer*> *_observers;
};

class Observer{
public:
    ~Observer();
    virtual void Update(Subject* theChangedSubject) = 0;

protected:
    Observer();
};

class ILoggable{
    ILoggable();
    ~ILoggable();
    virtual string stringToLog() = 0;
};

class LogObserver{
public:
    LogObserver();
    static void writeToFile(string s);
};

#endif //COMP335_P_LOGGINGOBSERVER_H
