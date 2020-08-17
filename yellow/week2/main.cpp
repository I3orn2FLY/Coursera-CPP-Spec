#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

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

//bool IsPalindrom(const string &str) {
//    for (int i = 0; i <= static_cast<int>(str.length()); ++i) {
//        if (str[i] != str[str.length() - 1 - i]) {
//            return false;
//        }
//    }
//    return true;
//}

bool CorrectIsPalindrom(const string &str) {
    for (int i = 0; i <= static_cast<int>(str.length()); ++i) {
        if (str[i] != str[str.length() - 1 - i]) {
            return false;
        }
    }
    return true;
}

void AssertString(const string &str) {
    AssertEqual(IsPalindrom(str), CorrectIsPalindrom(str));
}

string create_string(const int &N, const char &c) {
    stringstream ss;
    for (int i = 0; i < N; i++) {
        ss << c;
    }
    return ss.str();
}

void testAll() {
    AssertEqual(IsPalindrom(""), true);
    AssertEqual(IsPalindrom("a"), true);
    AssertEqual(IsPalindrom("b"), true);
    AssertEqual(IsPalindrom("7"), true);
    AssertEqual(IsPalindrom("g"), true);
    AssertEqual(IsPalindrom("z"), true);
    AssertEqual(IsPalindrom("gz  "), false);
    AssertEqual(IsPalindrom("gz  zg"), true);
    AssertEqual(IsPalindrom("gza zg"), false);
    AssertEqual(IsPalindrom("gg gg"), true);
    AssertEqual(IsPalindrom("gggz"), false);
    AssertEqual(IsPalindrom("aaba"), false);
    AssertEqual(IsPalindrom("abba"), true);
    AssertEqual(IsPalindrom("abcba"), true);
    AssertEqual(IsPalindrom("abcbba"), false);
    AssertEqual(IsPalindrom("678678"), false);
    AssertEqual(IsPalindrom("67876"), true);
    AssertEqual(IsPalindrom("678761"), false);
    AssertEqual(IsPalindrom("abcbbbbcba"), true);
    AssertEqual(IsPalindrom("abcbb7bbcba"), true);
    AssertEqual(IsPalindrom("abcbbbabbcba"), false);
    AssertEqual(IsPalindrom("7bcbbbabbcb8"), false);
    AssertEqual(IsPalindrom("7aaaaaaa8"), false);
    AssertEqual(IsPalindrom("7aaaaaaa"), false);
    AssertEqual(IsPalindrom("aaaaaaa8"), false);
    AssertEqual(IsPalindrom("7778aaaaaaa7778"), false);
    AssertEqual(IsPalindrom("7778aaaaaa7778"), false);

    {
        string s = create_string(1000, '7');
        AssertEqual(IsPalindrom(s), true);


        s[499] = 'b';

        AssertEqual(IsPalindrom(s), false);
    }

    {
        string s = create_string(1000, '8');
        AssertEqual(IsPalindrom(s), true);

        s[0] = '9';
        AssertEqual(IsPalindrom(s), false);

        s[0] = '8';
        s[s.length() - 1] = '1';
        AssertEqual(IsPalindrom(s), false);


        s = create_string(1000, '8');
        s[50] = ' ';
        AssertEqual(IsPalindrom(s), false);
    }
}


int main() {
    TestRunner runner;
    runner.RunTest(testAll, "TestALL");


    return 0;
}
