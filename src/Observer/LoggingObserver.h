//
// Created by Gin on 2022-03-01.
//
#include <vector>
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
    void Notify();

protected:
    Subject();

private:
    vector<Observer *> *_observers {};
};

class Observer{
public:
    Observer();
    ~Observer();
    virtual void Update(Subject* theChangedSubject) = 0;
};

class ILoggable{
public:
    ILoggable();

private:
    ~ILoggable();
    virtual string stringToLog() = 0;
};

class LogObserver: Observer{
public:
    LogObserver();
    ~LogObserver();
    static void writeToFile(string s);
};

#endif //COMP335_P_LOGGINGOBSERVER_H
