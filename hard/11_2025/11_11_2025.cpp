#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Daily Coding Problem: Problem #46 [Hard] - 11/11/25
    //
    // This problem was asked by Amazon.
    // Given a string, find the longest palindromic contiguous substring.
    // If there are more than one with the maximum length, return any one.
    //
    // For example:
    // The longest palindromic substring of "aabcdcb" is "bcdcb".
    // The longest palindromic substring of "bananas" is "anana".

    string longestPalindromicContiguousSubstring(const string &s) {
        int n = s.size();
        if (n == 0) return "";

        // dp[i][j] true if substr from i to j is a palindrome
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int start = 0;
        int maxLen = 1;

        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        // length = 2
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxLen = 2;
            }
        }

        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;

                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    if (len > maxLen) {
                        start = i;
                        maxLen = len;
                    }
                }
            }
        }

        return s.substr(start, maxLen);
    }

};

int main() {
    Solution s;
    // Daily Coding Problem: Problem #46 [Hard] - 11/11/25

    string s1 = "aabcdcb";
    string s2 = "bananas";

    cout << "Expected: bcdcb, got: " << s.longestPalindromicContiguousSubstring(s1) << endl;
    cout << "Expected: anana, got: " << s.longestPalindromicContiguousSubstring(s2) << endl;

    return 0;
}
