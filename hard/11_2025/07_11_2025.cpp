    #include <iostream>
    #include <vector>
    using namespace std;

    // Daily Coding Problem: Problem #42 [Hard] - 07/11/25
    //
    // This problem was asked by Google.
    // Given a list of integers S and a target number k, write a function
    // that returns a subset of S that adds up to k. If such a subset cannot be made,
    // then return null.
    //
    // Integers can appear more than once in the list. You may assume all
    // numbers in the list are positive.
    //
    // For example, given S = [12, 1, 61, 5, 9, 2] and k = 24,
    // return [12, 9, 2, 1] since it sums up to 24.

    class Solution {
    public:
        vector<int> subsetSum(vector<int>& s, int k) {
            int n = s.size();
            vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, false));

            dp[0][0] = true;
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j <= k; j++) {
                    dp[i][j] = dp[i - 1][j];
                    if (j >= s[i - 1]) {
                        dp[i][j] = dp[i][j] || dp[i - 1][j - s[i - 1]];
                    }
                }
            }

            if (!dp[n][k]) return {};

            vector<int> subset;
            int i = n, j = k;
            while (i > 0 && j > 0) {
                if (!dp[i - 1][j]) {
                    subset.push_back(s[i - 1]);
                    j -= s[i - 1];
                }
                i--;
            }

            return subset;
        }
    };

    int main() {
        // Daily Coding Problem: Problem #42 [Hard] - 07/11/25
        Solution s;
        vector<int> nums = {12, 1, 61, 5, 9, 2};
        int k = 67;

        for (int num : s.subsetSum(nums, k)) {
            cout << num << " ";
        }
        cout << endl;

        return 0;
    }
