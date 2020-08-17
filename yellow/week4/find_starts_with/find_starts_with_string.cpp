//
// Created by kenny on 17/08/2020.
//

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template<typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, const string &prefix) {

    auto start = lower_bound(range_begin, range_end, prefix);

    // empty or all elements are smaller than s_pre
    if (start == range_end || (*start).rfind(prefix) != 0) return make_pair(start, start);
    string s_pre(prefix);
    *prev(end(s_pre)) = *prev(end(s_pre)) + 1;
    auto finish = lower_bound(start, range_end, s_pre);
    return make_pair(start, finish);
}

int main() {
    const vector<string> sorted_strings = {"moscow", "motovilikha", "murmansk"};

    const auto mo_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
    for (auto it = mo_result.first; it != mo_result.second; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    const auto mt_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), "mt");
    cout << (mt_result.first - begin(sorted_strings)) << " " <<
         (mt_result.second - begin(sorted_strings)) << endl;

    const auto na_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), "na");
    cout << (na_result.first - begin(sorted_strings)) << " " <<
         (na_result.second - begin(sorted_strings)) << endl;

    return 0;
}
