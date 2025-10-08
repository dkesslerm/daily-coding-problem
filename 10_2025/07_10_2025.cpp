#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Daily Coding Problem: Problem #12 [Hard] - 7/10/25
    int numberOfSteps(int n) {
        if (n == 1) return 1;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }

    int generalizedNumberOfSteps(int n, vector<int>& X) {
        if (n == 1) return 1;
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
