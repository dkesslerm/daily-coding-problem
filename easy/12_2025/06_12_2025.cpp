#include <iostream>
#include <algorithm>
#include <random>
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
    int rand7() {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distr(1, 7);

        return distr(gen);
    }

    int rand5FromRand7() {
        int res;
        do {
            res = rand7();
        } while (res > 5);

        return res;
    }

    void printResults(int n) {
        cout << "RESULTS, n = " << n << endl;
        vector<int> times(5, 0);

        for (int i = 0; i < n; i++) {
            times[rand5FromRand7() - 1]++;
        }

        for (int i = 0; i < 5; i++) {
            cout << i + 1 << ": " << times[i] << ", in percentage: " << (double)times[i] * 100.0 / n << "%" << endl;
        }
    }

};

int main() {
    // Daily Coding Problem: Problem #70 [Easy] - 05/12/25
    Solution s;

    s.printResults(1000000);

    return 0;
}
