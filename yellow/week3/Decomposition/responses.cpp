//
// Created by kenny on 14/08/2020.
//

#include "responses.h"

ostream &operator<<(ostream &os, const BusesForStopResponse &r) {
    if (r.buses.empty()) {
        os << "No stop";
    } else {
        for (const string &bus :r.buses) {
            cout << bus << " ";
        }
    }
    return os;
}

ostream &operator<<(ostream &os, const StopsForBusResponse &r) {
    if (r.stops.empty()) {
        return os << "No bus";
    }
    bool first = true;
    for (const auto &[stop, buses] : r.stops) {
        if (first) {
            first = false;
        } else {
            os << endl;
        }
        os << "Stop " << stop << ": ";
        if (buses.empty()) os << "no interchange";
        for (const string &other_bus : buses) os << other_bus << " ";
    }


    return os;
}

ostream &operator<<(ostream &os, const AllBusesResponse &r) {

    if (r.buses_to_stops.empty()) {
        os << "No buses";
    } else {
        bool first = true;
        for (const auto &bus_item : r.buses_to_stops) {
            if (first) {
                first = false;
            } else {
                os << endl;
            }
            os << "Bus " << bus_item.first << ": ";
            for (const string &stop : bus_item.second) {
                os << stop << " ";
            }
        }
    }
    return os;
}
