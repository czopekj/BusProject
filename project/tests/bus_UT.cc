#include <gtest/gtest.h>

#include <iostream>
#include <string>
#include <list>
#include <string>

#include "../src/bus.h"
#include "../src/route.h"
#include "../src/stop.h"
#include "../src/passenger_loader.h"
#include "../src/passenger_unloader.h"
#include "../src/passenger.h"
#include "../src/passenger_generator.h"
#include "../src/random_passenger_generator.h"

using namespace std;

class BusTests : public ::testing::Test {
protected:
  Bus *bus, *bus1;
  PassengerLoader* pass_loader;
  PassengerUnloader* pass_unloader;
  Route *route, *route1;
  Stop *stop1, *stop2, *stop3, *stop4;
  Stop ** stops;
  Passenger *p, *p1;
  string busName = "Bus";


  virtual void SetUp() {
    pass_loader = new PassengerLoader();
    pass_unloader = new PassengerUnloader();
    p = new Passenger(4, "Joe");
    p = new Passenger(2, "Bob");

    stop1 = new Stop(1, 1.0, 1.0);
    stop2 = new Stop(2, 2.0, 2.0);
    stop3 = new Stop(3, 3.0, 3.0);
    stop4 = new Stop(4, 4.0, 4.0);

    stops = new Stop *[4];

    stops[0] = stop1;
    stops[1] = stop2;
    stops[2] = stop3;
    stops[3] = stop4;

    double * distances = new double[3];
    for(int i = 1; i <= 3; i++)
    {
      distances[i-1] = 3;
    }

    list<double> prods;
    prods.push_back(.5);
    prods.push_back(.3);
    prods.push_back(.7);
    prods.push_back(.5);

    list<Stop *> stopList;
    stopList.push_back(stop1);
    stopList.push_back(stop2);
    stopList.push_back(stop3);
    stopList.push_back(stop4);
    string name = "route";

    RandomPassengerGenerator* rando = new RandomPassengerGenerator(prods, stopList);

    route = new Route(name, stops, distances, 4, rando);
    route1 = route->Clone();

    bus = new Bus(busName, route, route1, 1, 1.0);
  }

  virtual void TearDown() {
    delete pass_loader;
    delete pass_unloader;
    delete bus;
    delete route;
    delete route1;
    delete stop1;
    delete stop2;
    delete stop3;
    delete stop4;
    delete stops;
    stop1 = NULL;
    stop2 = NULL;
    stop3 = NULL;
    stop4 = NULL;
    stops = NULL;
    route1 = NULL;
    bus = NULL;
    route = NULL;
    pass_loader = NULL;
    pass_unloader = NULL;
    bus = NULL;
  }
};

// check passenger before/after
// make a stop w a passenger, dest stop 2
// make stop 2 1 pass, dest stop 4
//

TEST_F(BusTests, Constructor) {
  EXPECT_EQ(bus->GetNextStop()->GetId(), stop1->GetId());
  EXPECT_EQ(bus->GetName(), busName);
  EXPECT_EQ(bus->GetNumPassengers(), 0);
  EXPECT_EQ(bus->GetCapacity(), 1);

};

TEST_F(BusTests, IsTripComplete) {
  EXPECT_EQ(bus->IsTripComplete(), false);
  for(int i = 0; i < 30; i++)
  {
    bus->Update();
  }
  EXPECT_EQ(bus->IsTripComplete(), true);
};

TEST_F(BusTests, LoadPassenger) {
  EXPECT_EQ(bus->LoadPassenger(p), true);
  EXPECT_EQ(bus->LoadPassenger(p), false);
};

TEST_F(BusTests, Move) {
  bus->LoadPassenger(p);
  int origWait = p->GetTotalWait();
  int next = bus->GetNextStop()->GetId();
  bus->Move();
  EXPECT_EQ(p->GetTotalWait(), origWait+1);
  bus->Move();
  bus->Move();
  EXPECT_NE(bus->GetNextStop()->GetId(), next);
  EXPECT_EQ(bus->Move(), true);
  for(int i = 0; i < 30; i++)
  {
    bus->Update();
  }
  EXPECT_EQ(bus->Move(), false);
}
