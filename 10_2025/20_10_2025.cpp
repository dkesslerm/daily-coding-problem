#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

// Daily Coding Problem: Problem #25 [Hard] - 20/10/25
//
// This problem was asked by Facebook.
// Implement regular expression matching with the following special characters:

//     . (period) which matches any single character
//     * (asterisk) which matches zero or more of the preceding element

// That is, implement a function that takes in a string and a valid regular expression
// and returns whether or not the string matches the regular expression.

// For example, given the regular expression "ra." and the string "ray", your function should return true.
// The same regular expression on the string "raymond" should return false.
// Given the regular expression ".*at" and the string "chat", your function should return true.
// The same regular expression on the string "chats" should return false.
class Solution {
public:
    bool expressionMatchesString(const string& s, const string& expr) {
        int n = s.size();
        int m = expr.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;

        for (int j = 1; j <= m; j++) {
            if (expr[j - 1] == '*' && j >= 2) {
                dp[0][j] = dp[0][j - 2];
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (expr[j - 1] == '.' || expr[j - 1] == s[i - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (expr[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2];
                    if (expr[j - 2] == '.' || expr[j - 2] == s[i - 1]) {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
            }
        }

        return dp[n][m];


    }
};

int main() {
    // Daily Coding Problem: Problem #25 [Hard] - 20/10/25
    Solution s;
    string expr1 = "ra.", s1 = "ray", s1f = "raymond";
    string expr2 = ".*at", s2 = "chat", s2f = "chats";

    cout << s.expressionMatchesString(s1, expr1) << endl;
    cout << s.expressionMatchesString(s2, expr2) << endl;


    return 0;
}
