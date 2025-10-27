#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Daily Coding Problem: Problem #9 [Hard] - 4/10/25

    // This problem was asked by Airbnb.
    // Given a list of integers, write a function that returns
    // the largest sum of non-adjacent numbers. Numbers can be
    // 0 or negative.
    //
    // For example:
    // [2, 4, 6, 2, 5] should return 13, since we pick 2, 6, and 5.
    // [5, 1, 1, 5] should return 10, since we pick 5 and 5.
    //
    // Follow-up: Can you do this in O(N) time and constant space?
    //
    // This is a variant of the house robber problem (in this version,
    // numbers can be 0 or negative insted of just positive). The same
    // dynamic programming algorithm works just fine!
    //
    // In order to get to constant space, we have to realize that we
    // don't need the whole dp vector, just the last two elements from it.
    // In 02_10_2025.cpp you have an example that uses the same idea.
    int largestSumOfNonAdjacentNumbers(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        // vector<int> dp(n, 0);
        // dp[0] = nums[0];
        // dp[1] = max(nums[0], nums[1]);
        int befPrev = nums[0];
        int prev = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            // dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
            int current = max(prev, befPrev + nums[i]);

            befPrev = prev;
            prev = current;
        }

        return prev;
    }
};

int main() {
    Solution s;

    // Daily Coding Problem: Problem #9 [Hard] - 4/10/25
    vector<int> nums = {5, 1, 1, 5}; // expected 10 = 5 + 5
    vector<int> nums2 = {2, 4, 6, 2, 5}; // expected 13 = 2 + 6 + 5
    cout << s.largestSumOfNonAdjacentNumbers(nums) << endl;

    return 0;
}
