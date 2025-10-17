#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// Daily Coding Problem: Problem #19 [Medium] - 14/10/25

// This problem was asked by Facebook.
// A builder is looking to build a row of N houses that can be of K different colors.
// He has a goal of minimizing cost while ensuring that no two neighboring houses
// are of the same color.

// Given an N by K matrix where:
//   - The nth row and kth column represents the cost to build the nth house
//     with kth color.
// Return the minimum cost which achieves this goal.

// For example, given the matrix:
// [
//   [17, 2, 17],
//   [16, 16, 5],
//   [14, 3, 19]
// ]
// The minimum cost is 10, achieved by painting the houses with colors in the order:
// House 1 -> Color 2 (Cost: 2)
// House 2 -> Color 3 (Cost: 5)
// House 3 -> Color 2 (Cost: 3)

class Solution {
public:
    int houseMinCost(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int k = matrix[0].size();
        vector<int> dp(k, 0);
        vector<int> prev_dp(k, 0);

        for (int i = 0; i < k; i++) {
            dp[i] = matrix[0][i];
        }

        for (int i = 1; i < n; i++) {
            int min1 = 1e6, min2 = 1e6;

            for (int j = 0; j < k; j++) {
                if (dp[j] < min1) {
                    min2 = min1;
                    min1 = dp[j];
                } else if (dp[j] < min2) {
                    min2 = dp[j];
                }
            }

            for (int j = 0; j < k; j++) {
                if (dp[j] == min1) {
                    dp[j] = min2 + matrix[i][j];
                } else {
                    dp[j] = min1 + matrix[i][j];
                }
            }
        }

        return *min_element(dp.begin(), dp.end());
    }

};

int main() {
    // Daily Coding Problem: Problem #19 [Medium] - 14/10/25
    Solution s;
    vector<vector<int>> matrix = {
        {17, 2, 17},
        {16, 5, 17},
        {14, 3, 19},
    };
    vector<vector<int> > costs = {
            { 1, 5, 7 }, { 5, 8, 4 }, { 3, 2, 9 }, { 1, 2, 4 }
        };

    cout << s.houseMinCost(matrix) << endl;

    return 0;
}
