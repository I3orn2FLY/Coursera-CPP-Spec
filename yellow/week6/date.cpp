//
// Created by kenny on 19/08/2020.
//
#include "project_includes.h"
#include "date.h"

Date::Date(const int &year, const int &month, const int &day) : year_(year), month_(month), day_(day) {}

int Date::GetYear() const {
    return year_;
}

int Date::GetMonth() const {
    return month_;
}

int Date::GetDay() const {
    return day_;
}


Date ParseDate(istream &ss) {
    int day, month, year;
    ss >> year;
    ss.ignore();
    ss >> month;
    ss.ignore();
    ss >> day;
    return Date(year, month, day);
}


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