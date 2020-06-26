// @file abstract_bus_factory.h
// @copyright 2020 Josh Czopek

#ifndef SRC_ABSTRACT_BUS_FACTORY_H_
#define SRC_ABSTRACT_BUS_FACTORY_H_

#include <string>
#include "src/bus.h"
#include "src/route.h"

class AbstractBusFactory {
 public:
  virtual Bus * GenerateBus(std::string name, Route * out, Route * in,
    double speed = 1) = 0;
};
#endif  // SRC_ABSTRACT_BUS_FACTORY_H_
