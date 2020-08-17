//
// Created by kenny on 13/08/2020.
//
#include "sum_reverse_sort.h"
#include <algorithm>

using namespace std;

int Sum(int x, int y) {
    return x + y;
}

string Reverse(string s) {
    reverse(begin(s), end(s));
    return s;
}

void Sort(vector<int> &nums){
    sort(begin(nums), end(nums));
}



