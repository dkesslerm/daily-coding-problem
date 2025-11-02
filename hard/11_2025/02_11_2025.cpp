#include <iostream>
#include <vector>
using namespace std;

// Daily Coding Problem: Problem #38 [Hard] - 02/11/25
//
// This problem was asked by Microsoft.
// You have an N by N board. Write a function that, given N,
// returns the number of possible arrangements of the board
// where N queens can be placed on the board without
// threatening each other, i.e. no two queens share the same
// row, column, or diagonal.

class Solution {
public:
    int nQueens(int n) {
        int sum = 0;
        vector<bool> cols(n, false), d1(2 * n - 1, false), d2(2 * n - 1, false);
        backtrack(0, n, sum, cols, d1, d2);

        return sum;
    }

    void backtrack(int row, int n, int& sum, vector<bool>& cols, vector<bool>& d1, vector<bool>& d2) {
        if (row == n) {
            sum++;
            return;
        }

        for (int col = 0; col < n; col++) {
            int v1 = row - col + n - 1;
            int v2 = row + col;
            if (cols[col] || d1[v1] || d2[v2]) {
                continue;
            }

            cols[col] = d1[v1] = d2[v2] = true;
            backtrack(row + 1, n, sum, cols, d1, d2);
            cols[col] = d1[v1] = d2[v2] = false;
        }
    }
};

int main() {
    // Daily Coding Problem: Problem #38 [Hard] - 02/11/25
    Solution s;

    cout << s.nQueens(8) << endl;

    return 0;
}
