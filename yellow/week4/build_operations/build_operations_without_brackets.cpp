//
// Created by kenny on 17/08/2020.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <sstream>

using namespace std;


int main() {
    int x, N, val;
    char prev_op, curr_op;
    cin >> x >> N;
    if (N == 0) {
        cout << x << endl;
        exit(0);
    }

    cin >> prev_op >> val;
    stringstream ss;
    ss << x << " " << prev_op << " " << val;
    int break_count = 0;
    for (int i = 1; i < N; ++i) {
        cin >> curr_op >> val;
        if ((curr_op == '*' || curr_op == '/') && (prev_op == '-' || prev_op == '+')) {
            break_count += 1;
            ss << ")";
        }
        ss << " " << curr_op << " " << val;

        prev_op = curr_op;
    }

    for (int i = 0; i < break_count; ++i) {
        cout << "(";
    }
    cout << ss.str() << endl;

    return 0;

}