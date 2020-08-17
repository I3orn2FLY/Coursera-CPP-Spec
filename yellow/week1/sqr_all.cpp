#include <iostream>
#include <map>
#include <vector>

using namespace std;

template<typename T>
T Sqr(const T &t);

template<typename First, typename Second>
pair<First, Second> Sqr(const pair<First, Second> &p);

template<typename K, typename V>
map<K, V> Sqr(const map<K, V> &m);

template<typename T>
vector<T> Sqr(const vector<T> &v);


template<typename T>
T Sqr(const T &t) {
    return t * t;
}


template<typename First, typename Second>
pair<First, Second> Sqr(const pair<First, Second> &p) {
    auto res = p;
    res.first = Sqr(res.first);
    res.second = Sqr(res.second);
    return res;
}

template<typename K, typename V>
map<K, V> Sqr(const map<K, V> &m) {
    auto res = m;

    for (auto &x: res) {
        x.second = Sqr(x.second);
    }
    return res;
}

template<typename T>
vector<T> Sqr(const vector<T> &v) {
    vector<T> res = v;

    for (T &x: res) {
        x = Sqr(x);
    }

    return res;
}


int main() {
    // Пример вызова функции
    vector<int> v = {1, 2, 3};
    cout << "vector:";
    for (int x : Sqr(v)) {
        cout << ' ' << x;
    }
    cout << endl;

    map<int, pair<int, int>> map_of_pairs = {
            {4, {2, 2}},
            {7, {4, 3}}
    };
    cout << "map of pairs:" << endl;
    for (const auto &x : Sqr(map_of_pairs)) {
        cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }
}