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
    int one_third = res.size() / 3;
    auto end_1 = begin(res) + one_third;
    auto end_2 = end_1 + one_third;

    MergeSort(begin(res), end_1);
    MergeSort(end_1, end_2);
    MergeSort(end_2, end(res));

    vector<typename RandomIt::value_type> temp;

    merge(begin(res), end_1, end_1, end_2, back_inserter(temp));
    merge(begin(temp), end(temp), end_2, end(res), range_begin);

}

int main() {
    vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1, 5};
    MergeSort(begin(v), end(v));
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
