#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

class Rational {
public:
    Rational() {
        numerator = 0;
        denominator = 1;
    }

    Rational(int numerator, int denominator) {
        this->numerator = numerator;
        this->denominator = denominator;
        update();
    }

    int Numerator() const {
        return numerator;
    }

    int Denominator() const {
        return denominator;
    }

    void setRat(int n, int d) {
        this->numerator = n;
        this->denominator = d;
        update();
    }

private:
    int numerator, denominator;

    void update() {
        int d = __gcd(numerator, denominator);
        if ((numerator >= 0 && denominator >= 0) || (numerator < 0 && denominator < 0)) {
            numerator = abs(numerator / d);
        } else {
            numerator = -abs(numerator / d);
        }
        denominator = abs(denominator / d);
    }
};


bool operator==(const Rational &lhs, const Rational &rhs) {
    return lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator();
}

bool operator<(const Rational &lhs, const Rational &rhs) {
    return lhs.Numerator() * rhs.Denominator() < rhs.Numerator() * lhs.Denominator();
}

int main() {
    {
        const set<Rational> rs = {{1, 2},
                                  {1, 25},
                                  {3, 4},
                                  {3, 4},
                                  {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25},
                                  {1, 2},
                                  {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
