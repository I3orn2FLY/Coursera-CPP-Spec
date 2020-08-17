#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a, b, c;
    cin >> a >> b >> c;
    if (a == 0 && b != 0) {
        cout << -c / b;
    } else if (b == 0 && a != 0) {
        if (c == 0) {
            cout << 0;
        } else if (c / a < 0) {
            double x = sqrt(-c / a);
            cout << x << " " << -x;
        }
    } else if (a != 0 && b != 0 && c == 0) {
        cout << 0 << " " << -b / a;
    } else if (a != 0 && b != 0 && c != 0) {

        double D = b * b - 4.0 * a * c;
        if (D > 0) {
            double x1 = (-b + sqrt(D)) / 2 / a;
            double x2 = (-b - sqrt(D)) / 2 / a;
            cout << x1 << " " << x2;
        } else if (D == 0) {
            cout << -b / 2 / a;
        }
    }


    return 0;
}
