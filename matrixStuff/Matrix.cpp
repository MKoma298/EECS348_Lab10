#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

class Matrix {
private:
    int n;
    vector<vector<int>> nums;

public:
    Matrix(int size = 0) {
        n = size;
        nums.resize(n, vector<int>(n, 0));
    }

    int getSize() const {
        return n;
    }

    void set(int row, int col, int value) {
        if (row >= 0 && row < n && col >= 0 && col < n)
            nums[row][col] = value;
    }

    int get(int row, int col) const {
        return nums[row][col];
    }

    void print() const {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << setw(8) << nums[i][j];
            }
            cout << endl;
        }
    }

    Matrix operator+(const Matrix& other) const {
        Matrix result(n);

        if (n != other.n) {
            cout << "Matrices must be the same size" << endl;
            return result;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                result.set(i, j, get(i, j) + other.get(i, j));
            }
        }
        return result;
    }
    Matrix operator*(const Matrix& other) const {
        Matric result(n);
        if (n != other.n) {
            cout << "Matrices must be the same size" << endl;
            return result;

        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int sum = 0;

                for (int k = 0; k < n; k++) {
                    sum += get (i, k) * other.get(k, j);
                }
            }
        }
    }
};

void dSums(const Matrix& m) {
    int mainSum = 0;
    int secondSum = 0;
    int n = m.getSize();

    for (int i = 0; i < n; i++) {
        mainSum += m.get(i, i);
        secondSum += m.get(i, n - 1 - i);
    }

    cout << "Main diagonal sum: " << mainSum << endl;
    cout << "Secondary diagonal sum: " << secondSum << endl;
}
void swapRows(Matrix& m, int row1 = 0, int row2 = 1) {
    int n = m.getSize();

    if (row1 < 0 || row2 < 0 || row1 >= n || row2 >= n) {
        cout << "Invalid rows" << endl;
        return;
    }

    for (int j = 0; j < n; j++) {
        int temp = m.get(row1, j);
        m.set(row1, j, m.get(row2, j));
        m.set(row2, j, temp);
    }
    m.print();
}
void swapCols(Matrix& m, int col1 = 0, int col2 = 1) {
    int n = m.getSize();

    if (col1 < 0 || col2 < 0 || col1 >= n || col2 >= n) {
        cout << "Invalid columns" << endl;
        return;
    }

    for (int j = 0; j < n; j++) {
        int temp = m.get(j, col1);
        m.set(j, col1, m.get(j, col2));
        m.set(j, col2, temp);
    }
    m.print();
}
