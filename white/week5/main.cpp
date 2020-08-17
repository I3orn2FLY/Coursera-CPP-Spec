#include <iostream>
#include <string>
#include <set>
#include <map>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <vector>


using namespace std;


class Date {
public:
    int GetYear() const {
        return year;
    }

    int GetMonth() const {
        return month;
    }

    int GetDay() const {
        return day;
    }

    Date() {
        year = 0;
        month = 0;
        day = 0;
    }

    Date(int day, int month, int year) {
        this->day = day;
        this->month = month;
        this->year = year;
        checkDate();
    }

    Date(const string &date) {
        stringstream ss(date);

        int sign = GetSign(ss);
        this->year = CheckAndGetNum(ss, sign);
        MoveAndCheckDelim(ss);

        sign = GetSign(ss);
        this->month = CheckAndGetNum(ss, sign);
        MoveAndCheckDelim(ss);


        sign = GetSign(ss);
        this->day = CheckAndGetNum(ss, sign);
        if (!ss.eof()) throw runtime_error("Wrong date format: " + ss.str());


        checkDate();
    }

private:
    int year, month, day;

    void checkDate() const {
        if (month < 1 || month > 12) {
            throw runtime_error("Month value is invalid: " + to_string(month));
        }
        if (day < 1 || day > 31) {
            throw runtime_error("Day value is invalid: " + to_string(day));
        }
    }

    static int GetSign(stringstream &ss) {
        if (ss.peek() == '-') {
            ss.ignore(1);
            return -1;
        } else if (ss.peek() == '+') {
            ss.ignore(1);
        }
        return 1;
    }

    static int CheckAndGetNum(stringstream &ss, int sign) {
        if (!isdigit(ss.peek())) {
            throw runtime_error("Wrong date format: " + ss.str());
        }
        int num;
        ss >> num;
        return num * sign;
    }

    static void MoveAndCheckDelim(stringstream &ss) {
        if (ss.peek() != '-') {
            throw runtime_error("Wrong date format: " + ss.str());
        }
        ss.ignore(1);
    }

};


bool operator<(const Date &lhs, const Date &rhs) {
    if (lhs.GetYear() != rhs.GetYear()) {
        return lhs.GetYear() < rhs.GetYear();
    } else if (lhs.GetMonth() != rhs.GetMonth()) {
        return lhs.GetMonth() < rhs.GetMonth();
    } else {
        return lhs.GetDay() < rhs.GetDay();
    }
}

bool operator==(const Date &lhs, const Date &rhs) {
    return lhs.GetYear() == rhs.GetYear() && lhs.GetMonth() == rhs.GetMonth() && lhs.GetDay() == rhs.GetDay();
}


ostream &operator<<(ostream &os, const Date &date) {
    os << setw(4) << setfill('0') << date.GetYear() << '-';
    os << setw(2) << setfill('0') << date.GetMonth() << '-';
    os << setw(2) << setfill('0') << date.GetDay();
    return os;
}


class Database {
public:
    void AddEvent(const Date &date, const string &event) {
        bd[date][event];
    }

    bool DeleteEvent(const Date &date, const string &event) {
        if (bd.count(date) && bd[date].count(event)) {
            bd[date].erase(event);
            if (bd[date].empty()) {
                bd.erase(date);
            }
            cout << "Deleted successfully" << endl;
            return true;
        } else {
            cout << "Event not found" << endl;
            return false;
        }

    }

    int DeleteDate(const Date &date) {
        int N = 0;

        if (bd.count(date)) {

            for (const auto &item: bd[date]) {
                N += 1;
            }

            bd.erase(date);
        }
        cout << "Deleted " << N << " events" << endl;

        return N;
    }

    void Find(const Date &date) const {
        if (bd.count(date)) {
            for (const auto &item: bd.at(date)) {
                cout << item.first << endl;
            }
        }
    }

    void Print() const {
        for (const auto &item: bd) {
            if (item.first.GetYear() < 0) {
                continue;
            }
            for (const auto &event: bd.at(item.first)) {
                cout << item.first << " " << event.first << endl;
            }
        }
    }

private:
    map<Date, map<string, int>> bd;
};

int main() {
    Database db;

    string line;
    while (getline(cin, line)) {
        if (line.length() == 0) continue;
        stringstream ss(line);
        string cmd;
        ss >> cmd;
        if (cmd == "Add" || cmd == "Del" || cmd == "Find") {
            string date_str;
            ss >> date_str;
            Date date;
            try {
                date = Date(date_str);
            } catch (runtime_error &r) {
                cout << r.what() << endl;
                continue;
            }

            if (cmd == "Add") {
                string event;
                ss >> event;
                db.AddEvent(date, event);
            } else if (cmd == "Del") {
                string event;
                if (ss >> event) {
                    db.DeleteEvent(date, event);
                } else {
                    db.DeleteDate(date);
                }
            } else {
                db.Find(date);
            }

        } else if (cmd == "Print") {
            db.Print();
        } else {
            cout << "Unknown command: " << cmd << endl;
        }
    }

    return 0;
}