#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Daily Coding Problem: Problem #12 [Hard] - 7/10/25

    // This problem was asked by Amazon.
    // There exists a staircase with N steps, and you can climb up either
    // 1 or 2 steps at a time. Given N, write a function that returns the
    // number of unique ways you can climb the staircase. The order of the
    // steps matters.
    //
    // For example, if N is 4, then there are 5 unique ways:
    //
    //     1, 1, 1, 1
    //     2, 1, 1
    //     1, 2, 1
    //     1, 1, 2
    //     2, 2
    //
    // Follow up: What if, instead of being able to climb 1 or 2 steps at a time,
    // you could climb any number from a set of positive integers X?
    // For example, if X = {1, 3, 5}, you could climb 1, 3, or 5 steps
    // at a time.

    int numberOfSteps(int n) {
        if (n == 1) return 1;
        vector<int> dp(n + 1, 0);
        // could do it with just curr, prev, befprev to get it to O(1) memory!
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }

    int generalizedNumberOfSteps(int n, vector<int>& X) {
        if (n == 1) return 1;
        // i'm not so sure of how I could make this one O(1) space,
        // but there's surely a way.
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        sort(X.begin(), X.end());

        for (int i = 1; i <= n; i++) {
            for (int x : X) {
                if (x > i) break;
                dp[i] += dp[i - x];
            }
        }

        return dp[n];
    }
};

int main() {
    Solution s;

    // Daily Coding Problem: Problem #12 [Hard] - 7/10/25
    int n = 10;
    vector<int> X = {1, 3, 5};

    cout << s.generalizedNumberOfSteps(n, X) << endl;

    return 0;
}
