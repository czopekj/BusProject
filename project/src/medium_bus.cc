// @file medium_bus.cc
// @copyright 2020 Josh Czopek

#include "src/medium_bus.h"

MediumBus::MediumBus(std::string name, Route * out, Route * in,
    double speed) : Bus(name, out, in, 60, speed) {
}

void MediumBus::Report(std::ostream& out) {
  out << "Name: " << name_ << std::endl;
  out << "Type: Medium Bus" << std::endl;
  out << "Speed: " << speed_ << std::endl;
  out << "Distance to next stop: " << distance_remaining_ << std::endl;
  out << "\tPassengers (" << passengers_.size() << "): " << std::endl;
  for (std::list<Passenger *>::iterator it = passengers_.begin();
                                        it != passengers_.end(); it++) {
    (*it)->Report(out);
  }
}
