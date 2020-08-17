//
// Created by kenny on 17/08/2020.
//

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include <string>

using namespace std;


template<typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
        RandomIt range_begin, RandomIt range_end,
        char prefix) {

    string s_pre(1, prefix);

    auto start = lower_bound(range_begin, range_end, s_pre);

    // empty or all elements are smaller than s_pre
    if (start == range_end or (*start)[0] != prefix) return make_pair(start, start);

    ++s_pre[0];
    auto finish = lower_bound(range_begin, range_end, s_pre);
    return make_pair(start, finish);
}

//int main() {
//    const vector<string> sorted_strings = {"lemon", "moscow", "murmansk", "vologda"};
//
//    const auto m_result =
//            FindStartsWith(begin(sorted_strings), end(sorted_strings), 'm');
//    for (auto it = m_result.first; it != m_result.second; ++it) {
//        cout << *it << " ";
//    }
//    cout << endl;
//
//    const auto p_result =
//            FindStartsWith(begin(sorted_strings), end(sorted_strings), 'p');
//    cout << (p_result.first - begin(sorted_strings)) << " " <<
//         (p_result.second - begin(sorted_strings)) << endl;
//
//    const auto z_result =
//            FindStartsWith(begin(sorted_strings), end(sorted_strings), 'z');
//    cout << (z_result.first - begin(sorted_strings)) << " " <<
//         (z_result.second - begin(sorted_strings)) << endl;
//
//
//    return 0;
//}
