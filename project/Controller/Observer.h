//
// Created by lifka on 18/06/17.
//

#ifndef PROJECT_OBSERVER_H
#define PROJECT_OBSERVER_H


#include "../Model/NotifyCode.h"

class Observer {
public:
    virtual void update(NotifyCode){};
};


#endif //PROJECT_OBSERVER_H
