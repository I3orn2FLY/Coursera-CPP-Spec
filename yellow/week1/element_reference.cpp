#include <iostream>
#include <map>
#include <vector>

using namespace std;

template<typename K, typename V>
V &GetRefStrict(map<K, V> &m, K key) {
    if (!m.count(key)) {
        throw runtime_error("Key Not Found");
    }
    return m[key];
}


int main() {
    map<int, string> m = {{0, "value"}};
    string &item = GetRefStrict(m, 0);
    item = "newvalue";
    cout << m[0] << endl; // выведет newvalue
}