// @file medium_bus_factory.h
// @copyright 2020 Josh Czopek

#ifndef SRC_MEDIUM_BUS_FACTORY_H_
#define SRC_MEDIUM_BUS_FACTORY_H_

#include <string>
#include "src/abstract_bus_factory.h"
#include "src/bus.h"
#include "src/medium_bus.h"

class MediumBusFactory : public AbstractBusFactory {
 public:
  Bus * GenerateBus(std::string name, Route * out, Route * in,
    double speed = 1) {
      Bus * bus = new MediumBus(name, out, in, speed);
      return bus;
  }
};
#endif  // SRC_MEDIUM_BUS_FACTORY_H_
