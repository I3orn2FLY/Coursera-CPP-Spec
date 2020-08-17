#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    bool first = false;
    for (int i = 0; i < s.size(); ++i) {
        if (!first && s[i] == 'f') {
            first = true;
        } else if (first && s[i] == 'f') {
            cout << i;
            return 0;
        }
    }

    if (!first) cout << -2; else cout << -1;

    return 0;
}
