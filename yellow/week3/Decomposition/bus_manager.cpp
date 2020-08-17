//
// Created by kenny on 14/08/2020.
//

#include "bus_manager.h"

void BusManager::AddBus(const string &bus, const vector<string> &stops) {
    buses_to_stops[bus] = stops;
    for (string stop : stops) {
        stops_to_buses[stop].push_back(bus);
    }
}

BusesForStopResponse BusManager::GetBusesForStop(const string &stop) const {
    BusesForStopResponse res;
    if (!stops_to_buses.empty() && stops_to_buses.count(stop)) res.buses = stops_to_buses.at(stop);
    return res;
}

StopsForBusResponse BusManager::GetStopsForBus(const string &bus) const {
    StopsForBusResponse res;
    if (!buses_to_stops.empty() && buses_to_stops.count(bus)) {
        for (const string &stop : buses_to_stops.at(bus)) {
            pair<string, vector<string>> p;
            p.first = stop;
            for (const string &other_bus : stops_to_buses.at(stop)) {
                if (bus != other_bus) {
                    p.second.push_back(other_bus);
                }
            }
            res.stops.push_back(p);
        }
    }

    return res;

}

AllBusesResponse BusManager::GetAllBuses() const {
    AllBusesResponse r;
    r.buses_to_stops = buses_to_stops;
    return r;
}
