//
// Created by kenny on 14/08/2020.
//

#ifndef WEEK3_BUS_MANAGER_H
#define WEEK3_BUS_MANAGER_H

#include <string>
#include <vector>
#include <iostream>
#include <map>
#include "responses.h"

using namespace std;

class BusManager {
public:
    void AddBus(const string &bus, const vector<string> &stops);

    BusesForStopResponse GetBusesForStop(const string &stop) const;

    StopsForBusResponse GetStopsForBus(const string &bus) const;

    AllBusesResponse GetAllBuses() const;
private:
    map<string, vector<string>> buses_to_stops, stops_to_buses;
};


#endif //WEEK3_BUS_MANAGER_H
