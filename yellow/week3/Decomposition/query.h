//
// Created by kenny on 14/08/2020.
//

#ifndef WEEK3_QUERY_H
#define WEEK3_QUERY_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;


enum class QueryType {
    NewBus,
    BusesForStop,
    StopsForBus,
    AllBuses
};

struct Query {
    QueryType type;
    string bus;
    string stop;
    vector<std::string> stops;
};

istream &operator>>(istream &is, Query &q) ;

#endif //WEEK3_QUERY_H
