#include <iostream>

#include <iostream>

using namespace std;

int main() {
    string a, b, c;
    cin >> a >> b >> c;
    if (a <= b && a <= c) {
        cout << a << endl;
    } else if (c <= b && c <= a) {
        cout << c << endl;
    } else if (b <= a && b <= c) {
        cout << b << endl;
    }

}
