// @file large_bus_factory.h
// @copyright 2020 Josh Czopek

#ifndef SRC_LARGE_BUS_FACTORY_H_
#define SRC_LARGE_BUS_FACTORY_H_

#include <string>
#include "src/abstract_bus_factory.h"
#include "src/bus.h"
#include "src/large_bus.h"

class LargeBusFactory : public AbstractBusFactory {
 public:
  Bus * GenerateBus(std::string name, Route * out, Route * in,
    double speed = 1) {
      Bus * bus = new LargeBus(name, out, in, speed);
      return bus;
  }
};
#endif  // SRC_LARGE_BUS_FACTORY_H_
