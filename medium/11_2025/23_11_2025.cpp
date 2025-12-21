#include <iostream>
#include <stack>
#include <algorithm>
#include <sstream>
using namespace std;

// Daily Coding Problem: Problem #58 [Medium] - 23/11/25
//
// This problem was asked by Amazon.
// A sorted array of integers was rotated an unknown number of times.
// Given such an array, find the index of the element in the array in
// faster than linear time. If the element doesn't exist in the array, return null.
//
// For example, given the array [13, 18, 25, 2, 8, 10] and the element 8,
// return 4 (the index of 8 in the array).
//
// You can assume all the integers in the array are unique.

class Solution {
public:
    int findElement(vector<int>& array, int element) {
        int l = 0;
        int r = array.size() - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;
            if (array[m] == element) {
                return m;
            }

            if (array[l] <= array[m]) {
                if (element >= array[l] && element < array[m]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            } else {
                if (element > array[m] && element <= array[r]) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
        }

        return -1;
    }
};

int main() {
    // Daily Coding Problem: Problem #58 [Medium] - 23/11/25
    Solution s;

    vector<int> nums = {13, 18, 25, 2, 8, 10};
    int element = 8;

    cout << s.findElement(nums, element) << endl;

    return 0;
}
