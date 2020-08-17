#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>

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

ostream &operator<<(ostream &stream, const Rational &rat) {
    stream << rat.Numerator() << "/" << rat.Denominator();

    return stream;
}

istream &operator>>(istream &stream, Rational &rat) {
    int n = rat.Numerator(), d = rat.Denominator();
    if(stream >> n) {
        stream.ignore(1);
        stream >> d;
        rat.setRat(n, d);
    }
    return stream;

}


int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 3;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 4;
        }
    }

    cout << "OK" << endl;
    return 0;
}
