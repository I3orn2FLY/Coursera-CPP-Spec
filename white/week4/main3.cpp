#include <iostream>
#include <exception>
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
        if (denominator == 0) {
            throw invalid_argument("");
        }
        int d = __gcd(numerator, denominator);
        if ((numerator >= 0 && denominator >= 0) || (numerator < 0 && denominator < 0)) {
            numerator = abs(numerator / d);
        } else {
            numerator = -abs(numerator / d);
        }
        denominator = abs(denominator / d);
    }
};

Rational operator+(const Rational &lhs, const Rational &rhs) {
    if (lhs.Denominator() == rhs.Denominator()) {
        return Rational(lhs.Numerator() + rhs.Numerator(), lhs.Denominator());
    } else {
        return Rational(lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(),
                        lhs.Denominator() * rhs.Denominator());
    }
}

Rational operator-(const Rational &lhs, const Rational &rhs) {
    if (lhs.Denominator() == rhs.Denominator()) {
        return Rational(lhs.Numerator() - rhs.Numerator(), lhs.Denominator());
    } else {
        return Rational(lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(),
                        lhs.Denominator() * rhs.Denominator());
    }
}


Rational operator/(const Rational &lhs, const Rational &rhs) {
    if (rhs.Numerator() == 0) {
        throw domain_error("domain error");
    }
    return Rational(lhs.Numerator() * rhs.Denominator(), rhs.Numerator() * lhs.Denominator());

}

Rational operator*(const Rational &lhs, const Rational &rhs) {
    return Rational(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());

}

ostream &operator<<(ostream &stream, const Rational &rat) {
    stream << rat.Numerator() << "/" << rat.Denominator();

    return stream;
}

istream &operator>>(istream &stream, Rational &rat) {
    int n = rat.Numerator(), d = rat.Denominator();
    if (stream >> n) {
        stream.ignore(1);
        stream >> d;
        rat.setRat(n, d);
    }
    return stream;

}

int main() {
    Rational lhs, rhs;
    char op;
    try {
        cin >> lhs >> op >> rhs;
        switch (op) {
            case '+':
                cout << lhs + rhs << endl;
                break;

            case '-':
                cout << lhs - rhs << endl;
                break;

            case '*':
                cout << lhs * rhs << endl;
                break;

            case '/':
                cout << lhs / rhs << endl;
                break;
        }
    } catch (invalid_argument &ex) {
        cout << "Invalid argument" << endl;
    } catch (domain_error &er) {
        cout << "Division by zero" << endl;
    }


    return 0;
}
