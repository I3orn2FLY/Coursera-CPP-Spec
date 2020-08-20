#pragma once

#include <memory>
#include <iomanip>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    for (const auto &i:v) os << i << " ";
//    cout << endl;
    return os;
}