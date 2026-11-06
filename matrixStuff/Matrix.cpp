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

    Matric operator+(cibst Matrix& other) const {
        Matrix result(n);

        if (n != other.n) {
            cout << "Matrices must be the same size" << endl;
        }
    }