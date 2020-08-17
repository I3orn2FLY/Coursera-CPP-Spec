#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

template<class T>
ostream &operator<<(ostream &os, const vector<T> &s) {
    os << "{";
    bool first = true;
    for (const auto &x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template<class T>
ostream &operator<<(ostream &os, const set<T> &s) {
    os << "{";
    bool first = true;
    for (const auto &x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template<class K, class V>
ostream &operator<<(ostream &os, const map<K, V> &m) {
    os << "{";
    bool first = true;
    for (const auto &kv : m) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << kv.first << ": " << kv.second;
    }
    return os << "}";
}

template<class T, class U>
void AssertEqual(const T &t, const U &u, const string &hint = {}) {
    if (t != u) {
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u;
        if (!hint.empty()) {
            os << " hint: " << hint;
        }
        throw runtime_error(os.str());
    }
}

void Assert(bool b, const string &hint) {
    AssertEqual(b, true, hint);
}

class TestRunner {
public:
    template<class TestFunc>
    void RunTest(TestFunc func, const string &test_name) {
        try {
            func();
            cerr << test_name << " OK" << endl;
        } catch (exception &e) {
            ++fail_count;
            cerr << test_name << " fail: " << e.what() << endl;
        } catch (...) {
            ++fail_count;
            cerr << "Unknown exception caught" << endl;
        }
    }

    ~TestRunner() {
        if (fail_count > 0) {
            cerr << fail_count << " unit tests failed. Terminate" << endl;
            exit(1);
        }
    }

private:
    int fail_count = 0;
};

int GetDistinctRealRootCount(double a, double b, double c) {
    if (a == 0 && b != 0) {
        return 1;
    } else if (b == 0 && a != 0) {
        if (c == 0) {
            return 1;
        } else if (c / a < 0) {
            return 2;
        }
    } else if (a != 0 && c == 0) {
        return 2;
    } else if (a != 0) {

        double D = b * b - 4.0 * a * c;
        if (D > 0) {
            return 2;
        } else if (D == 0) {
            return 1;
        }
    }
    return 0;
}

int Correct(double a, double b, double c) {
    if (a == 0 && b != 0) {
        return 1;
    } else if (b == 0 && a != 0) {
        if (c == 0) {
            return 1;
        } else if (c / a < 0) {
            return 2;
        }
    } else if (a != 0 && c == 0) {
        return 2;
    } else if (a != 0) {

        double D = b * b - 4.0 * a * c;
        if (D > 0) {
            return 2;
        } else if (D == 0) {
            return 1;
        }
    }
    return 0;
}

void testABC(double a, double b, double c) {
    AssertEqual(Correct(a, b, c), GetDistinctRealRootCount(a, b, c));
}

void testAll() {
    vector<double> A = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<double> B = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<double> C = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (const double &a:A) {
        for (const double &b:B) {
            for (const double &c:C) {
                if (a == 0 && b == 0 && c == 0) continue;
                testABC(a, b, c);
            }
        }
    }

}


int main() {
    TestRunner runner;
    runner.RunTest(testAll, "TestAll");
    return 0;
}
