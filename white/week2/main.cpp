//
// Created by kenny on 16.07.20.
//
#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

set<string> BuildMapValuesSet(const map<int, string> &m) {
    set<string> res;
    for (const auto &item: m) {
        res.insert(item.second);
    }
    return res;

}

int main() {
    int n;
    cin >> n;

    int routes = 0;
    int stops = 0;

    map<set<string>, int> route2bus;

    string stop;
    for (int i = 0; i < n; ++i) {
        set<string> route;
        cin >> stops;
        for (int j = 0; j < stops; ++j) {
            cin >> stop;
            route.insert(stop);
        }

        if (route2bus.count(route)) {
            cout << "Already exists for " << route2bus[route] << endl;
        } else {
            routes++;
            cout << "New bus " << routes << endl;
            route2bus[route] = routes;
        }
    }

}
