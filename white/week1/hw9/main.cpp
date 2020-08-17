#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> binary;
    int n;
    cin >> n;
    while (n > 0) {
        if (n % 2 == 0) {
            binary.push_back(0);
        } else {
            binary.push_back(1);
        }
        n = n / 2;
    }

    bool first = false;
    for (int i = binary.size() - 1; i >= 0; i--) {
        if (!first && binary[i] == 1) first = true;

        if (first) cout << binary[i];
    }

    return 0;
}
