//
// Created by kenny on 14/08/2020.
//

#ifndef WEEK3_RESPONSES_H
#define WEEK3_RESPONSES_H

#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;


struct BusesForStopResponse {
    vector<string> buses;
};
struct StopsForBusResponse {
    vector<pair<string, vector<string>>> stops;
};


struct AllBusesResponse {
    map<string, vector<string>> buses_to_stops;
};

ostream &operator<<(ostream &os, const BusesForStopResponse &r);


ostream &operator<<(ostream &os, const StopsForBusResponse &r);


ostream &operator<<(ostream &os, const AllBusesResponse &r);


#endif //WEEK3_RESPONSES_H
