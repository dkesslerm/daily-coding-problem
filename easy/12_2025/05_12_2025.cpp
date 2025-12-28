#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

// Daily Coding Problem: Problem #70 [Easy] - 05/12/25
//
// This problem was asked by Microsoft.
// A number is considered perfect if its digits sum up to exactly 10.
//
// Given a positive integer n, return the n-th perfect number.
//
// For example, given 1, you should return 19. Given 2, you should return 28.

class Solution {
public:
    int getNthPerfectNumber(int n) {
        int count = 0;
        int num = 0;
        for (num = 19;; num += 9) {
            int sum = 0;
            for (int i = num; i > 0; i /= 10) {
                sum += i % 10;
            }

            if (sum == 10) {
                count++;
            }

            if (count == n) {
                return num;
            }
        }

        return -1;
    }
};

int main() {
    // Daily Coding Problem: Problem #70 [Easy] - 05/12/25
    Solution s;

    cout << s.getNthPerfectNumber(5) << endl;

    return 0;
}
