//
// Created by kenny on 14/08/2020.
//
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void PrintVectorPart(const vector<int> &numbers) {
    auto loc = find_if(begin(numbers), end(numbers), [](const int &x) { return x < 0; });

    while (loc != begin(numbers)) {
        cout << *(--loc);
        if (loc != begin(numbers)) {
            cout << " ";
        }
    }

}


int main() {
    PrintVectorPart({6, 1, 8, -5, 4});
    cout << endl;
    PrintVectorPart({-6, 1, 8, -5, 4});  // ничего не выведется
    cout << endl;
    PrintVectorPart({6, 1, 8, 5, 4});
    cout << endl;
    return 0;
}
