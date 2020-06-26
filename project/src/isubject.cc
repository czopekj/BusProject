// @file isubject.cc
// @copyright 2020 Josh Czopek

#include "src/isubject.h"
#include "src/data_structs.h"

void ISubject::Attach(IObserver* obs) {
    observers_.push_back(obs);
}

void ISubject::Detach() {
    observers_.clear();
}

void ISubject::NotifyObservers(BusData info) {
    for(std::vector<IObserver*>::const_iterator iter = observers_.begin();
        iter != observers_.end(); iter++)
    {
        if(*iter != 0)
        {
            (*iter)->Notify(&info);
        }
    }
}