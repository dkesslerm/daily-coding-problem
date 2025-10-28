#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
#include <cassert>
using namespace std;

// Daily Coding Problem: Problem #33 [Easy] - 28/10/25
//
// This problem was asked by Microsoft.
// Compute the running median of a sequence of numbers.
// Given a stream of numbers, print out the median of
// the list so far each time a new element arrives.
//
// Notes:
// - For an even-length list the median is the average
//   of the two middle numbers.
//
// Example:
// Input:  [2, 1, 5, 7, 2, 0, 5]
// Output:
//  2
//  1.5
//  2
//  3.5
//  2
//  2
//  2
class Solution {
public:
    priority_queue<int> lower;
    priority_queue<int, vector<int>, greater<int>> upper;

    void addNum(int num) {
        if (lower.empty() || num <= lower.top()) {
            lower.push(num);
        } else {
            upper.push(num);
        }

        if (lower.size() > upper.size() + 1) {
            upper.push(lower.top());
            lower.pop();
        } else if (upper.size() > lower.size()) {
            lower.push(upper.top());
            upper.pop();
        }
    }

    double getMedian() {
        double median;
        if (lower.size() == upper.size()) {
            median = double(lower.top() + upper.top()) / 2;
        } else {
            median = lower.top();
        }

        return median;
    }

    void printMedian(vector<int> nums) {
        for (int i = 0; i < nums.size(); i++) {
            addNum(nums[i]);
            cout << getMedian() << endl;
        }
    }
};

int main() {
    // Daily Coding Problem: Problem #33 [Easy] - 28/10/25
    Solution s;
    vector<int> v = {2, 1, 5, 7, 2, 0, 5};
    s.printMedian(v);

    return 0;
}
