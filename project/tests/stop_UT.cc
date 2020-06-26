#include <gtest/gtest.h>

#include <iostream>
#include <string>
#include <list>
#include <string>

#include "../src/bus.h"
#include "../src/passenger.h"
#include "../src/stop.h"

using namespace std;

class StopTests : public ::testing::Test {
protected:
  Stop *stop;

  virtual void TearDown() {
    delete stop;
    stop = NULL;
  }
};

TEST_F(StopTests, Constructor) {
  stop = new Stop(12, 45.0, -93.5);
  EXPECT_EQ(stop->GetId(), 12);
  EXPECT_EQ(stop->GetLongitude(), 45.0);
  EXPECT_EQ(stop->GetLatitude(), -93.5);
  EXPECT_EQ(stop->GetNumPassengersPresent(), 0);
};
