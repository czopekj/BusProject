// @file large_bus.h
// @copyright 2020 Josh Czopek

#ifndef SRC_LARGE_BUS_H_
#define SRC_LARGE_BUS_H_

#include <string>
#include "src/bus.h"

class LargeBus : public Bus{
 public:
  LargeBus(std::string name, Route * out, Route * in, double speed = 1);
  void Report(std::ostream&);
};
#endif  // SRC_LARGE_BUS_H_
