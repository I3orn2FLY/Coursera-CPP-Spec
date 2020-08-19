//
// Created by kenny on 19/08/2020.
//

#include "node.h"


EmptyNode::EmptyNode() = default;

bool EmptyNode::Evaluate(const Date &date, const string &event) const {
    return true;
}


DateComparisonNode::DateComparisonNode(const Comparison &cmp, const Date &date) : _cmp(cmp), _date(date) {}

bool DateComparisonNode::Evaluate(const Date &date, const string &event) const {
    return true;
}


EventComparisonNode::EventComparisonNode(const Comparison &cmp, const string &event) : _cmp(cmp), _event(event) {}

bool EventComparisonNode::Evaluate(const Date &date, const string &event) const {
    return true;
}

LogicalOperationNode::LogicalOperationNode(const LogicalOperation &logOp, shared_ptr<const Node> &left,
                                           shared_ptr<const Node> &right) : _logOp(logOp), _left(left), _right(right) {}

bool LogicalOperationNode::Evaluate(const Date &date, const string &event) const {
    return true;
}
