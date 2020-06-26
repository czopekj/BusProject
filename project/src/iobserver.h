// @file iobserver.h
// @copyright 2020 Josh Czopek

#ifndef SRC_IOBSERVER_H_
#define SRC_IOBSERVER_H_

#include "src/data_structs.h"

class IObserver {
 public: 
  virtual void Notify(BusData * data) = 0;
};
#endif  // SRC_IOBSERVER_H_