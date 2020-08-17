#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>

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


class Person {
public:
    // Вы можете вставлять сюда различные реализации класса,
    // чтобы проверить, что ваши тесты пропускают корректный код
    // и ловят некорректный
    void ChangeFirstName(int year, const string &first_name) {
        updateFY(year);
        fnames[year] = first_name;
    }

    void ChangeLastName(int year, const string &last_name) {
        updateFY(year);
        lnames[year] = last_name;
    }

    string GetFullName(int year) const {
        if (empty or year < first_year) return "Incognito";
        auto fn = getName(true, year);
        auto ln = getName(false, year);
        if (fn.first && ln.first) {
            return fn.second + " " + ln.second;
        } else if (fn.first) {
            return fn.second + " with unknown last name";
        } else {
            return ln.second + " with unknown first name";
        }
    }

private:
    map<int, string> fnames, lnames;
    int first_year{};
    bool empty = true;

    void updateFY(const int &year) {
        if (empty) {
            first_year = year;
            empty = false;
        } else {
            first_year = min(year, first_year);
        }
    }

    pair<bool, string> getName(bool is_fn, const int &year) const {
        const auto names = is_fn ? fnames : lnames;
        bool found = false;
        string name;
        for (auto &item: names) {
            if (item.first > year) break;
            name = item.second;
            found = true;
        }
        return make_pair(found, name);
    }
};

class CorrectPerson {
public:
    // Вы можете вставлять сюда различные реализации класса,
    // чтобы проверить, что ваши тесты пропускают корректный код
    // и ловят некорректный
    void ChangeFirstName(int year, const string &first_name) {
        updateFY(year);
        fnames[year] = first_name;
    }

    void ChangeLastName(int year, const string &last_name) {
        updateFY(year);
        lnames[year] = last_name;
    }

    string GetFullName(int year) const {
        if (empty or year < first_year) return "Incognito";
        auto fn = getName(true, year);
        auto ln = getName(false, year);
        if (fn.first && ln.first) {
            return fn.second + " " + ln.second;
        } else if (fn.first) {
            return fn.second + " with unknown last name";
        } else {
            return ln.second + " with unknown first name";
        }
    }

private:
    map<int, string> fnames, lnames;
    int first_year{};
    bool empty = true;

    void updateFY(const int &year) {
        if (empty) {
            first_year = year;
            empty = false;
        } else {
            first_year = min(year, first_year);
        }
    }

    pair<bool, string> getName(bool is_fn, const int &year) const {
        const auto names = is_fn ? fnames : lnames;
        bool found = false;
        string name;
        for (auto &item: names) {
            if (item.first > year) break;
            name = item.second;
            found = true;
        }
        return make_pair(found, name);
    }
};


void run_change(bool is_fn, Person &person, CorrectPerson &correctPerson, const int &year, const string &name) {
    if (is_fn) {
        person.ChangeFirstName(year, name);
        correctPerson.ChangeFirstName(year, name);
    } else {
        person.ChangeLastName(year, name);
        correctPerson.ChangeLastName(year, name);
    }
}

void AssertFull(Person &person, CorrectPerson &correctPerson, const int &year) {
    AssertEqual(correctPerson.GetFullName(year), person.GetFullName(year));
}

void testAll() {
    {
        Person person;
        for (int i = -1000; i <= 1000; i++) {
            AssertEqual("Incognito", person.GetFullName(i));
        }
    }

    {
        Person person;
        CorrectPerson correctPerson;


        map<int, string> year_to_name;
        vector<int> years = {5, 19, -56, 126, -125, 561, 215, 456, 781, -985, 1000};


        for (int &year : years) {
            stringstream ss;
            ss << year << "_SALAM";
            year_to_name[year] = ss.str();
        }

        for (const auto &item : year_to_name) {
            person.ChangeFirstName(item.first, item.second);
            correctPerson.ChangeFirstName(item.first, item.second);
        }


        for (int i = -1000; i <= 1000; i++) {
            AssertFull(person, correctPerson, i);
        }

        years = {11, 6, -56, 126, -525, 361, 521, 6, 0, -905, 500};
        for (int &year : years) {
            stringstream ss;
            ss << year << "_SALAM";
            year_to_name[year] = ss.str();
        }

        for (const auto &item : year_to_name) {
            person.ChangeLastName(item.first, item.second);
            correctPerson.ChangeLastName(item.first, item.second);
        }

        for (int i = -1000; i <= 1000; i++) {
            AssertFull(person, correctPerson, i);
        }
    }

    {
        {
            Person person;
            CorrectPerson correctPerson;

            run_change(true, person, correctPerson, 5, "Incognito");
            for (int i = 0; i <= 10; i++) {
                AssertFull(person, correctPerson, i);
            }

            run_change(true, person, correctPerson, 5, "Incognito ");
            for (int i = 0; i <= 10; i++) {
                AssertFull(person, correctPerson, i);
            }

            run_change(true, person, correctPerson, 5, "Incognito  ");
            for (int i = 0; i <= 10; i++) {
                AssertFull(person, correctPerson, i);
            }

            run_change(false, person, correctPerson, 3, "Incognito");
            for (int i = 0; i <= 10; i++) {
                AssertFull(person, correctPerson, i);
            }

            run_change(false, person, correctPerson, 5, "Incognito ");
            for (int i = 0; i <= 10; i++) {
                AssertFull(person, correctPerson, i);
            }

            run_change(false, person, correctPerson, 8, "Incognito");
            for (int i = 0; i <= 10; i++) {
                AssertFull(person, correctPerson, i);
            }
        }


    }


}

int main() {
    TestRunner runner;
    runner.RunTest(testAll, "TestAll");
    return 0;
}
