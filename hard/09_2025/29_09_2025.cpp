#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Daily Coding Problem: Problem #4 [Hard] - 29/9/25 - Leetcode 41

    // This problem was asked by Stripe.
    //
    // Given an array of integers, find the first missing positive
    // integer in linear time and constant space. In other words,
    // find the lowest positive integer that does not exist in the
    // array. The array can contain duplicates and negative numbers
    // as well.
    //
    // For example:
    // - The input [3, 4, -1, 1] should give 2.
    // - The input [1, 2, 0] should give 3.
    // You can modify the input array in-place.

    int firstMissingPositive(vector<int> nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] < 1 || nums[i] > n) nums[i] = n + 1;
        }

        for (int i = 0; i < n; i++) {
            int num = abs(nums[i]);
            if (num > n) continue;

            num--;
            if (nums[num] > 0) {
                nums[num] *= -1;
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] >= 0) return i + 1;
        }

        return n + 1;
    }
};

int main() {
    Solution s;

    // Daily Coding Problem: Problem #4 [Hard] - 29/9/25 - Leetcode 41
    vector<int> nums = {-1, 1, 2};
    cout << s.firstMissingPositive(nums) << endl;

    return 0;
}
