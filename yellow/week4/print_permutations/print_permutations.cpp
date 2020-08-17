//
// Created by kenny on 14/08/2020.
//

#include <algorithm>
#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

int main() {
    int N;

    cin >> N;

    vector<int> v(N);
    iota(v.rbegin(), v.rend(), 1);

    while (true) {
        for (const auto &x:v) cout << x << " ";
        cout << endl;
        if (!prev_permutation(begin(v), end(v))) break;
    }


}