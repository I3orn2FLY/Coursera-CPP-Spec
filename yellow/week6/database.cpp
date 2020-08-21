//
// Created by kenny on 19/08/2020.
//

#include "database.h"
#include "date.h"

void Database::Add(const Date &date, const string &event) {
    if (!date_to_set_events.count(date) || !date_to_set_events[date].count(event)) {
        date_to_vector_events[date].push_back(event);
        date_to_set_events[date].insert(event);
    }
}


pair<Date, string> Database::Last(const Date &date) const {
    auto it = date_to_vector_events.upper_bound(date);
    if (it == begin(date_to_vector_events)) {
        throw invalid_argument("");
    }
    --it;
    if (it->second.empty()) {
        throw invalid_argument("");
    }

    return make_pair(it->first, it->second.back());
}


void Database::Print(ostream &os) const {
    for (const auto &[date, events]: date_to_vector_events) {
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

