#include <iostream>

using namespace std;

int main() {
    double n, a, b, x, y;
    cin >> n >> a >> b >> x >> y;
    if (n > a) {
        if (n <= b) {
            n -= n * x / 100;
        } else {
            n -= n * y / 100;
        }
    }

    cout << n;
    return 0;
}
