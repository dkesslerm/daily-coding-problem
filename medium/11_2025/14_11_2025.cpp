#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

// Daily Coding Problem: Problem #49 [Medium] - 14/11/25
//
// This problem was asked by Amazon.
// Given an array of numbers, find the maximum sum
// of any contiguous subarray of the array.
//
// For example, given the array [34, -50, 42, 14, -5, 86],
// the maximum sum would be 137, since we would take
// elements 42, 14, -5, and 86.
//
// Given the array [-5, -1, -8, -9], the maximum sum
// would be 0, since we would not take any elements.
//
// Do this in O(N) time.

class Solution {
public:
    int runningSum(vector<int>& nums) {
        int maxEndingHere = 0;
        int totalMax = 0;
        for (int num : nums) {
            maxEndingHere = max(0, maxEndingHere + num);
            totalMax = max(totalMax, maxEndingHere);
        }

        return totalMax;
    }

};

int main() {
    // Daily Coding Problem: Problem #49 [Medium] - 14/11/25
    Solution s;
    vector<int> nums = {-5, -1, -8, -9};
    cout << s.runningSum(nums) << endl;

    return 0;
}
