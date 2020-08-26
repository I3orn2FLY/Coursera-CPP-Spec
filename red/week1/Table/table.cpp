#include "test_runner.h"

using namespace std;

template<typename T>
class Table {
public:
    Table(size_t a, size_t b) {
        Resize(a, b);
    }

    vector<T> &operator[](int i) {
        return table[i];
    }

    vector<T> &operator[](int i) const {
        return table[i];
    }


    pair<size_t, size_t> Size() const {
        if (table.empty() || table[0].empty()) {
            return {0, 0};
        }
        return {table.size(), table[0].size()};
    }

    void Resize(size_t a, size_t b) {
        table.resize(a);
        for (auto &v: table) {
            v.resize(b);
        }
    }


private:
    vector<vector<T>> table;
};


void TestTable() {
    Table<int> t(1, 1);
    ASSERT_EQUAL(t.Size().first, 1u);
    ASSERT_EQUAL(t.Size().second, 1u);
    t[0][0] = 42;
    ASSERT_EQUAL(t[0][0], 42);
    t.Resize(3, 4);
    ASSERT_EQUAL(t.Size().first, 3u);
    ASSERT_EQUAL(t.Size().second, 4u);
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestTable);
    return 0;
}