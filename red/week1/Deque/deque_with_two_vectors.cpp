//
// Created by kenny on 26/08/2020.
//

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class Deque {
public:
    Deque() {}

    bool Empty() const {
        return backward.empty() && forward.empty();
    }

    size_t Size() const {
        return forward.size() + backward.size();
    }

    T &operator[](size_t idx) {
        return (idx < backward.size()) ? backward[backward.size() - idx - 1] : forward[idx - backward.size()];
    }

    const T &operator[](size_t idx) const {
        return (idx < backward.size()) ? backward[backward.size() - idx - 1] : forward[idx - backward.size()];
    }

    T &At(size_t idx) {
        if (idx >= this->Size()) throw out_of_range("");
        return (idx < backward.size()) ? backward[backward.size() - idx - 1] : forward[idx - backward.size()];
    }

    const T &At(size_t idx) const {
        if (idx >= this->Size()) throw out_of_range("");
        return (idx < backward.size()) ? backward[backward.size() - idx - 1] : forward[idx - backward.size()];
    }

    T &Front() {
        return (backward.empty()) ? forward[0] : backward[backward.size() - 1];
    }

    const T &Front() const {
        return (backward.empty()) ? forward[0] : backward[backward.size() - 1];
    }

    T &Back() {
        return (forward.empty()) ? backward[0] : forward[forward.size() - 1];
    }

    const T &Back() const {
        return (forward.empty()) ? backward[0] : forward[forward.size() - 1];
    }

    void PushFront(const T &t) {
        backward.push_back(t);
    }

    void PushBack(const T &t) {
        forward.push_back(t);
    }


private:
    vector<T> forward;
    vector<T> backward;

};


int main() {
    Deque<int> deq;

    deq.PushBack(5);
    deq.Front() = deq.Front() - 1;

    cout << deq.Front() << endl;


}