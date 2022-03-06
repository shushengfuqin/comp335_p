//
// Created by Gin on 2022-03-06.
//

#include "LoggingObserver.h"

using namespace std;


Subject::Subject() {
    _observers = new list<Observer*>();
}

Subject::~Subject(){
    delete _observers;
}

void Subject::Attach(Observer *obs){
    _observers->push_back(obs);
}

void Subject::Detach(Observer *obs) {
    _observers->remove(obs);
}

void Subject::Notify(ILoggable *il) {
    for(Observer* o: *_observers){
        o->Update(il);
    }
}

// Observer class methods

Observer::Observer() = default;;
Observer::~Observer() = default;;

// LogObserver class methods

LogObserver::LogObserver() = default;

LogObserver::LogObserver(Subject* s): _subject(s){
    _subject->Attach(this);
}

LogObserver::~LogObserver(){
    _subject->Detach(this);
}

void LogObserver::Update(ILoggable *il) {
    ofstream ofs;
    ofs.open("gameLog.txt", ofstream::app);
    ofs << il->stringToLog() << endl;
    ofs.close();
}

ILoggable::ILoggable() {

}

ILoggable::~ILoggable() {

}