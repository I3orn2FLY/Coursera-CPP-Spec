//
// Created by kenny on 27/08/2020.
//

#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <sstream>

using namespace std;

class Learner {
private:
    set<string> dict;

public:
    int Learn(const vector<string> &words) {
        int newWords = 0;
        for (const auto &word : words) {
            if (!dict.count(word)) {
                dict.insert(word);
                newWords++;
            }
        }
        return newWords;
    }

    vector<string> KnownWords() {
        vector<string> res;
        for (const auto &word: dict) {
            res.push_back(word);
        }
        return res;
    }
};

int main() {
    Learner learner;
    string line;
    while (getline(cin, line)) {
        vector<string> words;
        stringstream ss(line);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        cout << learner.Learn(words) << "\n";
    }
    cout << "=== known words ===\n";
    for (auto word : learner.KnownWords()) {
        cout << word << "\n";
    }
}