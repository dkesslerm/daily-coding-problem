#include <cstdlib>
#include <iostream>
#include <numeric>
#include <stack>
#include <algorithm>
#include <sstream>
using namespace std;

// Daily Coding Problem: Problem #66 [Medium] - 01/12/25
//
// This problem was asked by Square.
//
// Assume you have access to a function toss_biased() which returns
// 0 or 1 with a probability that's not 50-50 (but also not 0-100 or 100-0).
// You do not know the bias of the coin.
//
// Write a function to simulate an unbiased coin toss.

class Solution {
public:
    int tossBiased() {
        const double p = 0.73;  // any value strictly between 0 and 1, not 0.5

        double r = static_cast<double>(rand()) / RAND_MAX;
        return (r < p) ? 1 : 0;
    }

    int tossUnbiased() {
        int first, second;
        do {
            first = tossBiased();
            second = tossBiased();
        } while (first == second);

        return first;
    }

    void tossNTimes(int n) {
        int biasedHeads = 0, biasedTails = 0;
        int heads = 0, tails = 0;
        for (int i = 0; i < n; i++) {
            if (tossBiased() == 0) {
                biasedHeads++;
            } else {
                biasedTails++;
            }

            if (tossUnbiased() == 0) {
                heads++;
            } else {
                tails++;
            }
        }

        cout << "Tosses: " << n << endl;
        cout << "Biased coin results: " << biasedHeads << " heads, " << biasedTails << " tails." << endl;
        cout << "Unbiased coin results: " << heads << " heads, " << tails << " tails." << endl;
    }
};

int main() {
    // Daily Coding Problem: Problem #66 [Medium] - 01/12/25
    Solution s;

    s.tossNTimes(1000);

    return 0;
}
