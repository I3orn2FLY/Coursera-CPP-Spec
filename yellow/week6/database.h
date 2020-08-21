//
// Created by kenny on 19/08/2020.
//

#ifndef WEEK5_DATABASE_H
#define WEEK5_DATABASE_H

#include "date.h"

#include "node.h"

class Database {
public:
    void Add(const Date &date, const string &event);

    template<typename Pred>
    int RemoveIf(Pred p) {
        int N = 0;
        vector<Date> dates_to_erase;
        for (auto &[date, events]: date_to_vector_events) {
            auto i = remove_if(begin(events), end(events),
                               [p, date = date](const string &event) {
                                   return p(date, event);
                               });
            N += (end(events) - i);
            for (auto j = i; j != end(events); ++j) {
                date_to_set_events[date].erase(*j);
            }
            events.erase(i, end(events));
            if (events.empty()){
                dates_to_erase.push_back(date);
            }
        }

        for (const auto &date:dates_to_erase) {
            date_to_vector_events.erase(date);
            date_to_set_events.erase(date);
        }

        return N;
    }


    template<typename Pred>
    vector<pair<Date, string>> FindIf(Pred p) const {
        vector<pair<Date, string>> res;
        for (auto[date, events]: date_to_vector_events) {
            auto d = partition(begin(events), end(events),
                               [p, date = date](const string &event) {
                                   return p(date, event);
                               });
            for (auto i = begin(events); i != d; i++) {
                res.emplace_back(date, *i);
            }
        }

        return res;
    }

    pair<Date, string> Last(const Date &date) const;

    void Print(ostream &os) const;

private:
    map<Date, vector<string>> date_to_vector_events;
    map<Date, set<string>> date_to_set_events;


};


ostream &operator<<(ostream &os, const pair<Date, string> &p);

#endif //WEEK5_DATABASE_H
