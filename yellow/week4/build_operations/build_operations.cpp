//
// Created by kenny on 17/08/2020.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <sstream>

using namespace std;

enum class OP_TYPE {
    PLUS,
    MINUS,
    MULT,
    DIV
};

//int main() {
//    int x, N;
//    cin >> x >> N;
//    queue<pair<OP_TYPE, int>> q;
//    for (int i = 0; i < N; ++i) {
//        char c;
//        int v;
//        cin >> c >> v;
//        OP_TYPE op;
//        switch (c) {
//            case '+':
//                op = OP_TYPE::PLUS;
//                break;
//            case '-':
//                op = OP_TYPE::MINUS;
//                break;
//            case '*':
//                op = OP_TYPE::MULT;
//                break;
//            case '/':
//                op = OP_TYPE::DIV;
//                break;
//            default:
//                break;
//        }
//        q.push(make_pair(op, v));
//    }
//
//    stringstream ss;
//    for (int i = 0; i < N; ++i) {
//        ss << "(";
//    }
//    ss << x;
//    while (!q.empty()) {
//        ss << ")";
//        auto p = q.front();
//
//        switch (p.first) {
//            case OP_TYPE::PLUS:
//                ss << " + " << p.second;
//                break;
//            case OP_TYPE::MINUS:
//                ss << " - " << p.second;
//                break;
//            case OP_TYPE::MULT:
//                ss << " * " << p.second;
//                break;
//            case OP_TYPE::DIV:
//                ss << " / " << p.second;
//                break;
//        }
//
//        q.pop();
//    }
//
//
//    cout << ss.str() << endl;
//
//    return 0;
//
//}