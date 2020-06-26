// @file small_bus.h
// @copyright 2020 Josh Czopek

#ifndef SRC_SMALL_BUS_H_
#define SRC_SMALL_BUS_H_

#include <string>
#include "src/bus.h"

class SmallBus : public Bus{
 public:
  SmallBus(std::string name, Route * out, Route * in, double speed = 1);
  void Report(std::ostream&);
};
#endif  // SRC_SMALL_BUS_H_
