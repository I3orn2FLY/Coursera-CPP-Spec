//
// Created by kenny on 18/08/2020.
//
#include <iostream>
#include <sstream>
#include <iomanip>
#include <memory>
#include <vector>
#include <cmath>

using namespace std;


struct Figure {
public:

    virtual string Name() const = 0;

    virtual double Perimeter() const = 0;

    virtual double Area() const = 0;
};


struct Rect : public Figure {
public:
    Rect(const double &a, const double &b) : a_(a), b_(b) {}

    string Name() const override {
        return "RECT";
    }

    double Perimeter() const override {
        return 2 * (a_ + b_);
    }

    double Area() const override {
        return a_ * b_;
    }


private:
    const double a_, b_;
};

struct Triangle : public Figure {
public:
    explicit Triangle(const double &a, const double &b, const double c) : a_(a), b_(b), c_(c) {}

    string Name() const override {
        return "TRIANGLE";
    }

    double Perimeter() const override {
        return (a_ + b_ + c_);
    }

    double Area() const override {
        double s = Perimeter() / 2;
        return sqrt(s * (s - a_) * (s - b_) * (s - c_));
    }

private:
    const double a_, b_, c_;
};

struct Circle : public Figure {
public:
    Circle(const double &r) : r_(r) {}

    string Name() const override {
        return "CIRCLE";
    }

    double Perimeter() const override {
        return 2 * 3.14 * r_;
    }

    double Area() const override {
        return 3.14 * r_ * r_;
    }

private:
    const double r_;
};


shared_ptr<Figure> CreateFigure(istringstream &is) {
    string type;
    is >> type;
    if (type == "CIRCLE") {
        double r;
        is >> ws >> r;
        return make_shared<Circle>(r);
    } else if (type == "RECT") {
        double a, b;
        is >> ws >> a >> ws >> b;
        return make_shared<Rect>(a, b);
    } else {
        double a, b, c;
        is >> ws >> a >> ws >> b >> ws >> c;
        return make_shared<Triangle>(a, b, c);
    }


}

int main() {
    vector<shared_ptr<Figure>> figures;
    for (string line; getline(cin, line);) {
        istringstream is(line);

        string command;
        is >> command;
        if (command == "ADD") {
            // Пропускаем "лишние" ведущие пробелы.
            // Подробнее об std::ws можно узнать здесь:
            // https://en.cppreference.com/w/cpp/io/manip/ws
            is >> ws;
            figures.push_back(CreateFigure(is));
        } else if (command == "PRINT") {
            for (const auto &current_figure : figures) {
                cout << fixed << setprecision(3)
                     << current_figure->Name() << " "
                     << current_figure->Perimeter() << " "
                     << current_figure->Area() << endl;
            }
        }
    }
    return 0;
}