#include <gtest/gtest.h>

#include <iostream>
#include <string>
#include <list>
#include <string>

#include "../src/bus.h"
#include "../src/passenger.h"
#include "../src/stop.h"
#include "../src/route.h"
#include "../src/passenger_generator.h"
#include "../src/random_passenger_generator.h"

using namespace std;

class RouteTests : public ::testing::Test {
protected:
  Route *route;
  Stop *stop1, *stop2, *stop3, *stop4;
  Stop ** stops;

  virtual void TearDown() {
      delete route;
      delete stop1;
      delete stop2;
      delete stop3;
      delete stop4;
      delete stops;
      route = NULL;
      stop1 = NULL;
      stop2 = NULL;
      stop3 = NULL;
      stop4 = NULL;
      stops = NULL;
  }
};

TEST_F(RouteTests, Constructor) {
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

  EXPECT_EQ(route->GetStops().back()->GetId(), stop4->GetId());
  EXPECT_EQ(route->GetTotalRouteDistance(), 9);
  EXPECT_EQ(route->GetDestinationStop()->GetId(), stop1->GetId());
};

TEST_F(RouteTests, IsAtEnd) {
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

  EXPECT_EQ(route->IsAtEnd(), false);
  route->ToNextStop();
  route->ToNextStop();
  route->ToNextStop();
  route->ToNextStop();
  EXPECT_EQ(route->IsAtEnd(), true);
}
