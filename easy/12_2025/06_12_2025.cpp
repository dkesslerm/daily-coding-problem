#include <iostream>
#include <algorithm>
#include <random>
using namespace std;

// Daily Coding Problem: Problem #71 [Easy] - 06/12/25
//
// Using a function rand7() that returns an integer
// from 1 to 7 (inclusive) with uniform probability,
// implement a function rand5() that returns an integer from 1 to 5 (inclusive).

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
    // Daily Coding Problem: Problem #71 [Easy] - 06/12/25
    Solution s;

    s.printResults(1000000);

    return 0;
}
