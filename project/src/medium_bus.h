// @file medium_bus.h
// @copyright 2020 Josh Czopek

#ifndef SRC_MEDIUM_BUS_H_
#define SRC_MEDIUM_BUS_H_

#include <string>
#include "src/bus.h"

class MediumBus : public Bus{
 public:
  MediumBus(std::string name, Route * out, Route * in, double speed = 1);
  void Report(std::ostream&);
};
#endif  // SRC_MEDIUM_BUS_H_
