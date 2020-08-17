//
// Created by kenny on 17/08/2020.
//
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


template<typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
    if (range_end - range_begin < 2) return;
    vector<typename RandomIt::value_type> res(range_begin, range_end);
    int half = res.size() / 2;

    MergeSort(begin(res), begin(res) + half);
    MergeSort(begin(res) + half, end(res));
    merge(begin(res), begin(res) + half, begin(res) + half, end(res), range_begin);
}


