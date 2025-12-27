#include <iostream>
#include <unordered_map>
#include <random>
using namespace std;

// Daily Coding Problem: Problem #65 [Easy] - 30/11/25
//
// This problem was asked by Amazon.
// Given a N by M matrix of numbers, print out the matrix in a clockwise spiral.
//
// For example, given the following matrix:
//
// [[1,  2,  3,  4,  5],
//  [6,  7,  8,  9,  10],
//  [11, 12, 13, 14, 15],
//  [16, 17, 18, 19, 20]]
//
// You should print out the following:
//
// 1
// 2
// 3
// 4
// 5
// 10
// 15
// 20
// 19
// 18
// 17
// 16
// 11
// 6
// 7
// 8
// 9
// 14
// 13
// 12

class Solution {
public:
    void printMatrixClockwise(vector<vector<int>> matrix) {
        int numPrinted = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int firstCol = 0, lastCol = m - 1, firstRow = 0, lastRow = n - 1;

        while (firstRow <= lastRow && firstCol <= lastCol) {
            for (int i = firstCol; i <= lastCol; i++) {
                cout << matrix[firstRow][i] << endl;
            }
            firstRow++;

            for (int i = firstRow; i <= lastRow; i++) {
                cout << matrix[i][lastCol] << endl;
            }
            lastCol--;

            if (firstRow <= lastRow) {
                for (int i = lastCol; i >= firstCol; i--) {
                    cout << matrix[lastRow][i] << endl;
                }
                lastRow--;
            }

            if (firstCol <= lastCol) {
                for (int i = lastRow; i >= firstRow; i--) {
                    cout << matrix[i][firstCol] << endl;
                }
                firstCol++;
            }
        }
    }
};

int main() {
    // Daily Coding Problem: Problem #63 [Easy] - 28/11/25
    Solution s;

    vector<vector<int>> matrix = {
        {1,  2,  3,  4,  5},
        {6,  7,  8,  9,  10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20}
    };

    s.printMatrixClockwise(matrix);

    return 0;
}
