#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Daily Coding Problem: Problem #4 [Hard] - 29/9/25 - Leetcode 41
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
