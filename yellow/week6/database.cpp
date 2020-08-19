//
// Created by kenny on 19/08/2020.
//

#include "database.h"
#include "date.h"

void Database::Add(const Date &date, const string &event) {
    bd[date].push_back(event);
}


void Database::Last(const Date &date) const {

}

template<typename Pred>
bool Database::RemoveIf(Pred p) {
    int N = 0;
    for (auto &[date, events]: bd) {
        for (const auto &event: events) {
            if (p(date, event)) {

//                events;
            }
        }
    }
    cout << "Deleted " << N << " events" << endl;

    return N;
}

template<typename Pred>
void Database::FindIf(Pred p) const {

}

void Database::Print(ostream &os) const {
    for (const auto &item: bd) {
        for (const auto &event: bd.at(item.first)) {
            os << item.first << " " << event.first << endl;
        }
    }
}




