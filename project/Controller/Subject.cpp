//
// Created by lifka on 18/06/17.
//

#include <iostream>
#include "Observer.h"
#include "Subject.h"
#include "../Model/NotifyCode.h"

void Subject::addObserver(Observer* o) {
    observers.push_back(o);
}

void Subject::notifyObservers(NotifyCode code, Piece piece) {
    for(std::vector<Observer*>::const_iterator it = observers.begin(); it != observers.end(); ++it){
        if(*it != 0) {
            (*it)->update(code, piece);
        }
    }
}

void Subject::notifyObservers(NotifyCode code) {
    for(std::vector<Observer*>::const_iterator it = observers.begin(); it != observers.end(); ++it){
        if(*it != 0) {
            (*it)->update(code);
        }
    }
}

void Subject::notifyObservers(NotifyCode code, int number) {
    for(std::vector<Observer*>::const_iterator it = observers.begin(); it != observers.end(); ++it){
        if(*it != 0) {
            (*it)->update(code, number);
        }
    }
}

void Subject::notifyObservers(NotifyCode code, KeyCode key) {
    for(std::vector<Observer*>::const_iterator it = observers.begin(); it != observers.end(); ++it){
        if(*it != 0) {
            (*it)->update(code, key);
        }
    }
}

void Subject::notifyObserversLine(NotifyCode code) {
    for(std::vector<Observer*>::const_iterator it = observers.begin(); it != observers.end(); ++it){
        if(*it != 0) {
            (*it)->updateLine(code);
        }
    }
}


