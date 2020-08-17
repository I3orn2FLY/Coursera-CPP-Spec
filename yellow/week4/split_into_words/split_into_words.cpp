//
// Created by kenny on 14/08/2020.
//
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> SplitIntoWords(const string &s) {
    auto start = begin(s);

    vector<string> res;
    while (start != end(s)) {
        auto new_start = find_if(start, end(s), [](char c) {
            return c == ' ';
        });

        string word(start, new_start);
        res.push_back(word);
        start = new_start;
        if (start != end(s)) start += 1;
    }

    return res;
}


int main() {
    string s = "C Cpp Java Python";

    vector<string> words = SplitIntoWords(s);
    cout << words.size() << " ";
    for (auto it = begin(words); it != end(words); ++it) {
        if (it != begin(words)) {
            cout << "/";
        }
        cout << *it;
    }
    cout << endl;

    return 0;
}