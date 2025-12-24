#include <iostream>
#include <numeric>
#include <stack>
#include <algorithm>
#include <sstream>
using namespace std;

// Daily Coding Problem: Problem #60 [Medium] - 25/11/25
//
// This problem was asked by Facebook.
// There is an N by M matrix of zeroes. Given N and M, write a function to
// count the number of ways of starting at the top-left corner and getting to
// the bottom-right corner. You can only move right or down.

// For example, given a 2 by 2 matrix, you should return 2,
// since there are two ways to get to the bottom-right:

//     Right, then down
//     Down, then right

// Given a 5 by 5 matrix, there are 70 ways to get to the bottom-right.

class Solution {
public:
    int waysToExploreMatrix(int n, int m) {
        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[n - 1][m - 1] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (i == n - 1 && j == m - 1) continue;

                int down = (i + 1 < n) ? dp[i + 1][j] : 0;
                int right = (j + 1 < m) ? dp[i][j + 1] : 0;
                dp[i][j] = down + right;
            }
        }

        return dp[0][0];
    }
};

int main() {
    // Daily Coding Problem: Problem #60 [Medium] - 25/11/25
    Solution s;

    cout << "Expected: 70, got: " << s.waysToExploreMatrix(5, 5) << endl;

    return 0;
}
