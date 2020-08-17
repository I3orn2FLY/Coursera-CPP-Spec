#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


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
    int first_year;
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


int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    return 0;
}
