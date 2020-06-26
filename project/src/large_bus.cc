// @file large_bus.cc
// @copyright 2020 Josh Czopek

#include "src/large_bus.h"

LargeBus::LargeBus(std::string name, Route * out, Route * in,
    double speed) : Bus(name, out, in, 90, speed) {
}

void LargeBus::Report(std::ostream& out) {
  out << "Name: " << name_ << std::endl;
  out << "Type: Large Bus" << std::endl;
  out << "Speed: " << speed_ << std::endl;
  out << "Distance to next stop: " << distance_remaining_ << std::endl;
  out << "\tPassengers (" << passengers_.size() << "): " << std::endl;
  for (std::list<Passenger *>::iterator it = passengers_.begin();
                                        it != passengers_.end(); it++) {
    (*it)->Report(out);
  }
}
