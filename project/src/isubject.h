// @file isubject.h
// @copyright 2020 Josh Czopek

#ifndef SRC_ISUBJECT_H_
#define SRC_ISUBJECT_H_

#include <vector>
#include "src/iobserver.h"

class ISubject {
 public:
  void Attach(IObserver* obs);
  void Detach();
  void NotifyObservers(BusData info);

private:
 std::vector<IObserver*> observers_;
};

#endif  // SRC_ISUBJECT_H_