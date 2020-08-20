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
    bool res = false;
    switch (_cmp) {
        case Comparison::Less:
            res = date < _date;
            break;
        case Comparison::LessOrEqual:
            res = date < _date || date == _date;
            break;
        case Comparison::Greater:
            res = (!(date == _date)) && (!(date < _date));
            break;
        case Comparison::GreaterOrEqual:
            res = !(date < _date);
            break;
        case Comparison::Equal:
            res = date == _date;
            break;
        case Comparison::NotEqual:
            res = !(date == _date);
            break;
    }
    return res;
}


EventComparisonNode::EventComparisonNode(const Comparison &cmp, const string &event) : _cmp(cmp), _event(event) {}

bool EventComparisonNode::Evaluate(const Date &date, const string &event) const {
    switch (_cmp) {
        case Comparison::Less:
            return event < _event;
            break;
        case Comparison::LessOrEqual:
            return event < _event || event == _event;
            break;
        case Comparison::Greater:
            return (!(event == _event)) && (!(event < _event));
            break;
        case Comparison::GreaterOrEqual:
            return !(event < _event);
            break;
        case Comparison::Equal:
            return event == _event;
            break;
        case Comparison::NotEqual:
            return !(event == _event);
            break;
    }
}

LogicalOperationNode::LogicalOperationNode(const LogicalOperation &logOp, const shared_ptr<Node> &left,
                                           const shared_ptr<Node> &right) : _logOp(logOp), _left(left), _right(right) {}

bool LogicalOperationNode::Evaluate(const Date &date, const string &event) const {
    switch (_logOp) {
        case LogicalOperation::Or:
            return _left->Evaluate(date, event) || _right->Evaluate(date, event);
            break;
        case LogicalOperation::And:
            return _left->Evaluate(date, event) && _right->Evaluate(date, event);
            break;
    }
}
