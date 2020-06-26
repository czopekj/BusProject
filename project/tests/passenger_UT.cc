/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <gtest/gtest.h>

#include <iostream>
#include <string>
#include <list>
#include <string>

#include "../src/passenger_loader.h"
#include "../src/passenger_unloader.h"
#include "../src/passenger.h"
#include "../src/stop.h"

using namespace std;

/******************************************************
* TEST FEATURE SetUp
*******************************************************/
class PassengerTests : public ::testing::Test {
protected:
  PassengerLoader* pass_loader;
  PassengerUnloader* pass_unloader;
  Passenger *passenger, *passenger1, *passenger2;

  virtual void SetUp() {
    pass_loader = new PassengerLoader();
    pass_unloader = new PassengerUnloader();
  }

  virtual void TearDown() {
    delete pass_loader;
    delete pass_unloader;
    delete passenger;
    passenger = NULL;
    pass_loader = NULL;
    pass_unloader = NULL;
  }
};


/*******************************************************************************
 * Test Cases
 ******************************************************************************/
TEST_F(PassengerTests, Constructor) {
  passenger = new Passenger();
  EXPECT_EQ(passenger->GetTotalWait(), 0);
  EXPECT_EQ(passenger->GetDestination(), -1);
  EXPECT_EQ(passenger->IsOnBus(), false);
  passenger->GetOnBus();
  EXPECT_EQ(passenger->IsOnBus(), true);
};

TEST_F(PassengerTests, Report) {
  passenger = new Passenger(12, "John Doe");
  string exp_name = "Name: John Doe";
  string exp_dest = "Destination: 12";
  string exp_wait = "Total Wait: 0";
  testing::internal::CaptureStdout();
  passenger->Report(std::cout);
  string out = testing::internal::GetCapturedStdout();
  // testing::internal::CaptureStdout();
  int p1 = out.find(exp_name);
  int p2 = out.find(exp_dest);
  int p3 = out.find(exp_wait);

  EXPECT_GE(p1,0);
  EXPECT_GE(p2,0);
  EXPECT_GE(p3,0);
};

TEST_F(PassengerTests, TimeOnBus) {
  passenger = new Passenger();
  passenger->GetOnBus();
  EXPECT_EQ(passenger->IsOnBus(), true);
  for(int i = 0; i < 5; i++)
    passenger->Update();
  EXPECT_EQ(passenger->GetTotalWait(), 6);
};

TEST_F(PassengerTests, GetDestination) {
  passenger = new Passenger(12, "Joe");
  EXPECT_EQ(passenger->GetDestination(), 12);
};
