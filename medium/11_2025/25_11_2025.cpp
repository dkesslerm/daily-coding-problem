#include <iostream>
#include <numeric>
#include <stack>
#include <algorithm>
#include <sstream>
using namespace std;

// Daily Coding Problem: Problem #60 [Medium] - 25/11/25
//
// This problem was asked by Facebook.
// Given a multiset of integers, return whether it can be partitioned into two subsets whose sums are the same.
//
// For example, given the multiset {15, 5, 20, 10, 35, 15, 10}, it would return true,
// since we can split it up into {15, 5, 10, 15, 10} and {20, 35}, which both add up to 55.
//
// Given the multiset {15, 5, 20, 10, 35}, it would return false, since we can't split
// it up into two subsets that add up to the same sum.

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum % 2 != 0) {
            return false;
        }

        int target = totalSum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int n : nums) {
            for (int i = target; i >= n; i--) {
                if (dp[i]) continue;
                if (dp[i - n]) dp[i] = true;
                if (dp[target]) return true;
            }
        }

        return false;
    }
};

int main() {
    // Daily Coding Problem: Problem #60 [Medium] - 25/11/25
    Solution s;

    vector<int> nums = {15, 5, 20, 10, 35, 15, 10};

    cout << s.canPartition(nums) << endl;

    return 0;
}
