//
// Created by lifka on 18/06/17.
//

#ifndef PROJECT_SUBJECT_H
#define PROJECT_SUBJECT_H


#include <functional>
#include <vector>
#include "Observer.h"

class Subject {
private:
    std::vector<Observer* > observers;
public:
    void addObserver(Observer* o);
    void removeObserver(Observer* o);
    void notifyObservers(NotifyCode);
};


#endif //PROJECT_SUBJECT_H
