//
// Created by kenny on 19/08/2020.
//

#ifndef WEEK5_NODE_H
#define WEEK5_NODE_H

#include "project_includes.h"
#include "date.h"

enum class LogicalOperation {
    Or,
    And,
};

enum class Comparison {
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    Equal,
    NotEqual
};


class Node {
public:
    virtual bool Evaluate(const Date &date, const string &event) const = 0;
};


class EmptyNode : public Node {
public:
    EmptyNode();

    bool Evaluate(const Date &date, const string &event) const override;
};


class DateComparisonNode : public Node {
public:
    DateComparisonNode(const Comparison &cmp, const Date &date);

    bool Evaluate(const Date &date, const string &event) const override;

private:
    const Comparison _cmp;
    const Date _date;
};


class EventComparisonNode : public Node {
public:
    EventComparisonNode(const Comparison &cmp, const string &event);

    bool Evaluate(const Date &date, const string &event) const override;

private:
    const Comparison _cmp;
    const string _event;

};

class LogicalOperationNode : public Node {
public:
    LogicalOperationNode(const LogicalOperation &logOp, const shared_ptr<Node> &left, const shared_ptr<Node> &right);

    bool Evaluate(const Date &date, const string &event) const override;

private:
    const LogicalOperation _logOp;
    const shared_ptr<Node> _left, _right;
};


#endif //WEEK5_NODE_H
