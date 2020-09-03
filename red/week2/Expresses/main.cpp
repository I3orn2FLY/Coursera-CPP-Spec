//
// Created by kenny on 03/09/2020.
//
#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int q, s, f;
    cin >> q;

    map<int, set<int>> G;

    string cmd;
    for (int i = 0; i < q; ++i) {
        cin >> cmd >> s >> f;
        if (cmd == "ADD") {
            G[s].insert(f);
            G[f].insert(s);
        } else {
            auto s_it = G.find(s);
            if (s_it == end(G)) {
                cout << abs(f - s) << endl;
            } else {

                auto f_it = (*s_it).second.lower_bound(f);
                if (f_it == end((*s_it).second) || ((f_it != begin((*s_it).second)) && (f - *prev(f_it) < *f_it - f))) {
                    f_it = prev(f_it);
                }
                cout << min(abs(f - s), abs(*f_it - f)) << endl;
            }
        }
    }

}
