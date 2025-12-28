#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

// Daily Coding Problem: Problem #69 [Easy] - 04/12/25
//
// This problem was asked by Facebook.
// Given a list of integers, return the largest product
// that can be made by multiplying any three integers.
//
// For example, if the list is [-10, -10, 5, 2],
// we should return 500, since that's -10 * -10 * 5.
//
// You can assume the list has at least three integers.

class Solution {
public:
    int getLargestProductSorting(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        return max(nums[0] * nums[1] * nums[n - 1], nums[n - 1] * nums[n - 2] * nums[n - 3]);
    }

    int getLargestProductOptimal(vector<int>& nums) {
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        int min1 = INT_MAX, min2 = INT_MAX;

        for (int n : nums) {
            if (n > max1) {
                max3 = max2;
                max2 = max1;
                max1 = n;
            } else if (n > max2) {
                max3 = max2;
                max2 = n;
            } else if (n > max3) {
                max3 = n;
            }

            if (n < min1) {
                min2 = min1;
                min1 = n;
            } else if (n < min2) {
                min2 = n;
            }
        }

        return max(min1 * min2 * max1, max3 * max2 * max1);
    }
};

int main() {
    // Daily Coding Problem: Problem #69 [Easy] - 04/12/25
    Solution s;

    vector<int> nums = {-10, -10, -2, 2};

    cout << s.getLargestProductSorting(nums) << endl;
    cout << s.getLargestProductOptimal(nums) << endl;

    return 0;
}
