//
// Created by kenny on 14/08/2020.
//
#include <vector>
#include <algorithm>

using namespace std;

template<typename DataType>
void RemoveDuplicates(vector <DataType> &elements) {
    sort(begin(elements), end(elements));
    elements.erase(
            unique(begin(elements), end(elements)),
            elements.end());
}
