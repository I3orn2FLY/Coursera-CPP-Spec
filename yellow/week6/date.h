//
// Created by kenny on 19/08/2020.
//

#ifndef WEEK5_DATE_H
#define WEEK5_DATE_H

#include "project_includes.h"

class Date {
public:
    Date(const int &year, const int &month, const int &day);

    Date(const Date &date) {
        year_ = date.GetYear();
        month_ = date.GetMonth();
        day_ = date.GetDay();
    }

    int GetYear() const;

    int GetMonth() const;

    int GetDay() const;


private:
    int year_, month_, day_;
};

Date ParseDate(istream &is);

bool operator<(const Date &lhs, const Date &rhs);

bool operator==(const Date &lhs, const Date &rhs);

ostream &operator<<(ostream &os, const Date &date);

#endif //WEEK5_DATE_H
