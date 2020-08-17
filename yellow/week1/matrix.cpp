#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

class Matrix {
public:
    Matrix() {
        m.resize(0);
    }

    Matrix(const int &num_rows, const int &num_cols) {
        if (num_rows < 0 || num_cols < 0) throw out_of_range("");
        m.resize(num_rows);
        for (auto &v: m) {
            v.resize(num_cols);
        }
    }

    void Reset(const int &num_rows, const int &num_cols) {
        if (num_rows < 0 || num_cols < 0) throw out_of_range("");
        m.resize(num_rows);
        for (auto &v: m) {
            v.assign(num_cols, 0);
        }
    }

    int At(int i, int j) const {
        check_loc(i, j);
        return m[i][j];
    }

    int &At(int i, int j) {
        check_loc(i, j);
        return m[i][j];
    }

    int GetNumRows() const {
        return m.size();
    }

    int GetNumColumns() const {
        return m.empty() ? 0 : (int) m[0].size();
    }

private:
    vector<vector<int>> m;

    void check_loc(const int &i, const int &j) const {
        int n_rows = GetNumRows();
        int n_cols = GetNumColumns();

        if (i < 0 || j < 0 || i >= n_rows || j >= n_cols) throw out_of_range("");
    }
};

ostream &operator<<(ostream &os, const Matrix &mat) {

    os << mat.GetNumRows() << ' ' << mat.GetNumColumns() << endl;
    for (int i = 0; i < mat.GetNumRows(); ++i) {
        for (int j = 0; j < mat.GetNumColumns(); j++) {
            os << mat.At(i, j);
            if (j != mat.GetNumColumns() - 1) {
                os << " ";
            }

        }
        os << endl;
    }
    return os;
}

istream &operator>>(istream &is, Matrix &mat) {
    int rows, cols;

    is >> rows >> cols;
    mat = Matrix(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; j++) {
            is >> mat.At(i, j);
        }
    }

    return is;
}

bool operator==(const Matrix &lhs, const Matrix &rhs) {
    if (lhs.GetNumRows() != rhs.GetNumRows()) return false;
    if (lhs.GetNumColumns() != rhs.GetNumColumns()) return false;

    for (int i = 0; i < lhs.GetNumRows(); ++i) {
        for (int j = 0; j < lhs.GetNumColumns(); ++j) {
            if (lhs.At(i, j) != rhs.At(i, j)) return false;
        }
    }

    return true;
}

Matrix operator+(const Matrix &lhs, const Matrix &rhs) {
    if (lhs.GetNumRows() != rhs.GetNumRows()) throw invalid_argument("");
    if (lhs.GetNumColumns() != rhs.GetNumColumns()) throw invalid_argument("");
    Matrix res(lhs.GetNumRows(), lhs.GetNumColumns());
    for (int i = 0; i < lhs.GetNumRows(); ++i) {
        for (int j = 0; j < lhs.GetNumColumns(); ++j) {
            res.At(i, j) = lhs.At(i, j) + rhs.At(i, j);
        }
    }

    return res;
}


// * оператор сложения двух объектов класса Matrix

int main() {
    Matrix one;
    Matrix two;

    cin >> one >> two;
    cout << one + two << endl;
    return 0;
}
