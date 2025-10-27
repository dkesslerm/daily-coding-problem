#include <cstdlib>
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// Daily Coding Problem: Problem #18 [Hard] - 13/10/25

// This problem was asked by Google.
// Given an array of integers and a number k, where 1 <= k <= length
// of the array, compute the maximum values of each subarray of length k.
//
// For example, given array = [10, 5, 2, 7, 8, 7] and k = 3, we should get:
// [10, 7, 8, 8], since:
// 10 = max(10, 5, 2)
// 7  = max(5, 2, 7)
// 8  = max(2, 7, 8)
// 8  = max(7, 8, 7)
//
// Do this in O(n) time and O(k) space. You can modify the input array
// in-place and you do not need to store the results. You can simply
// print them out as you compute them.
class Solution {
public:
    void maxValues(vector<int> nums, int k) {
        deque<int> dq;

        for (int i = 0; i < nums.size(); i++) {
            if (!dq.empty() && dq.front() < i - k + 1) {
                dq.pop_front();
            }

            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            if (i >= k - 1) {
                cout << nums[dq.front()] << endl;
            }
        }
    }

};

int main() {
    // Daily Coding Problem: Problem #18 [Hard] - 13/10/25
    Solution s;

    s.maxValues({10, 5, 2, 7, 8, 7}, 3);

    return 0;
}
