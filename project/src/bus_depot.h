// @file bus_depot.h
// @copyright 2020 Josh Czopek

#ifndef SRC_BUS_DEPOT_H_
#define SRC_BUS_DEPOT_H_


#include "src/bus.h"
#include "src/route.h"
#include "src/small_bus_factory.h"
#include "src/medium_bus_factory.h"
#include "src/large_bus_factory.h"

class BusDepot {
 public:
  BusDepot();
  Bus* MakeBus(std::string, Route *, Route *, int);
 private:
  int currStrat = 0;
  int state = 0;
  SmallBusFactory sbf;
  MediumBusFactory mbf;
  LargeBusFactory lbf;
};

#endif  // SRC_BUS_DEPOT_H_