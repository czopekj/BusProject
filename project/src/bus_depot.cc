// @file bus_depot.cc
// @copyright 2020 Josh Czopek

#include <ctime>

#include "src/bus_depot.h"
BusDepot::BusDepot(){}
Bus* BusDepot::MakeBus(std::string name, Route * out, Route * in, int speed) 
{
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);

    int hour = now->tm_hour;
    Bus* ptr = 0;

    if(hour >= 6 && hour < 8) {
        if(currStrat == 1) {
            if(state == 0) {
                ptr = sbf.GenerateBus(name, out, in, speed);
                std::cout << "Bus Generated" << std::endl;
                std::cout << "Hour: " << hour << std::endl;
                std::cout << "Strategy: 1" << std::endl;
                std::cout << "Bus Size: Small" << std::endl;
                state = 1;
            } else if(state == 1) {
                ptr = mbf.GenerateBus(name, out, in, speed);
                std::cout << "Bus Generated" << std::endl;
                std::cout << "Hour: " << hour << std::endl;
                std::cout << "Strategy: 1" << std::endl;
                std::cout << "Bus Size: Medium" << std::endl;
                state = 0;
            }
        } else {
            currStrat = 1;
            ptr = sbf.GenerateBus(name, out, in, speed);
                std::cout << "Bus Generated" << std::endl;
                std::cout << "Hour: " << hour << std::endl;
                std::cout << "Strategy: 1" << std::endl;
                std::cout << "Bus Size: Small" << std::endl;
            state = 1;
        }
    } else if(hour >= 8 && hour < 15) {
        if(currStrat == 2) {
            if(state == 0) {
                ptr = mbf.GenerateBus(name, out, in, speed);
                std::cout << "Bus Generated" << std::endl;
                std::cout << "Hour: " << hour << std::endl;
                std::cout << "Strategy: 2" << std::endl;
                std::cout << "Bus Size: Medium" << std::endl;
                state = 1;
            } else if(state == 1) {
                ptr = lbf.GenerateBus(name, out, in, speed);
                std::cout << "Bus Generated" << std::endl;
                std::cout << "Hour: " << hour << std::endl;
                std::cout << "Strategy: 2" << std::endl;
                std::cout << "Bus Size: Large" << std::endl;
                state = 0;
            }
        } else {
            currStrat = 2;
            ptr = mbf.GenerateBus(name, out, in, speed);
                std::cout << "Bus Generated" << std::endl;
                std::cout << "Hour: " << hour << std::endl;
                std::cout << "Strategy: 2" << std::endl;
                std::cout << "Bus Size: Medium" << std::endl;
            state = 1;
        }
    } else if(hour >= 15 && hour < 20) {
        if(currStrat == 3) {
            if(state == 0) {
                ptr = sbf.GenerateBus(name, out, in, speed);
                std::cout << "Bus Generated" << std::endl;
                std::cout << "Hour: " << hour << std::endl;
                std::cout << "Strategy: 3" << std::endl;
                std::cout << "Bus Size: Small" << std::endl;
                state = 1;
            } else if(state == 1) {
                ptr = mbf.GenerateBus(name, out, in, speed);
                std::cout << "Bus Generated" << std::endl;
                std::cout << "Hour: " << hour << std::endl;
                std::cout << "Strategy: 3" << std::endl;
                std::cout << "Bus Size: Medium" << std::endl;
                state = 2;
            } else if(state == 2) {
                ptr = lbf.GenerateBus(name, out, in, speed);
                std::cout << "Bus Generated" << std::endl;
                std::cout << "Hour: " << hour << std::endl;
                std::cout << "Strategy: 3" << std::endl;
                std::cout << "Bus Size: Large" << std::endl;
                state = 0;
            }
        } else {
            currStrat = 3;
            ptr = sbf.GenerateBus(name, out, in, speed);
                std::cout << "Bus Generated" << std::endl;
                std::cout << "Hour: " << hour << std::endl;
                std::cout << "Strategy: 3" << std::endl;
                std::cout << "Bus Size: Small" << std::endl;
            state = 1;
        }
    } else {
        ptr = sbf.GenerateBus(name, out, in, speed);
                std::cout << "Bus Generated" << std::endl;
                std::cout << "Hour: " << hour << std::endl;
                std::cout << "Strategy: Small" << std::endl;
                std::cout << "Bus Size: Small" << std::endl;
    }
    return ptr;
}