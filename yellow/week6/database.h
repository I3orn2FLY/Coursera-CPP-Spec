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
    bool RemoveIf(Pred p);

    template<typename Pred>
    void FindIf(Pred p) const;

    void Last(const Date &date) const;

    void Print(ostream &os) const;

private:
    map<Date, vector<string>> bd;


};


#endif //WEEK5_DATABASE_H
