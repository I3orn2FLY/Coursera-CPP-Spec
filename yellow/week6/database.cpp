//
// Created by kenny on 19/08/2020.
//

#include "database.h"
#include "date.h"

void Database::Add(const Date &date, const string &event) {
    if (find(begin(bd[date]), end(bd[date]), event) == end(bd[date])) {
        bd[date].push_back(event);
    }
}


pair<Date, string> Database::Last(const Date &date) const {
    auto it = bd.upper_bound(date);
    if (it == begin(bd)) {
        throw invalid_argument("");
    }
    --it;
    if (it->second.empty()) {
        throw invalid_argument("");
    }

    return make_pair(it->first, it->second.back());
}


void Database::Print(ostream &os) const {
    for (const auto &[date, events]: bd) {
        for (const string &event: events) {
            auto p = make_pair(date, event);
            os << p << endl;
        }
    }
    flush(os);
}


ostream &operator<<(ostream &os, const pair<Date, string> &p) {
    os << p.first << " " << p.second;
    return os;
}

