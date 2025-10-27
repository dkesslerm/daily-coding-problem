#include <algorithm>
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

// Daily Coding Problem: Problem #31 [Easy] - 26/10/25
//
// This problem was asked by Google.
// The edit distance between two strings refers to the minimum number
// of character insertions, deletions, and substitutions required to
// change one string to the other. For example, the edit distance
// between "kitten" and "sitting" is three: substitute the 'k' for
// the 's', substitute the 'e' for the 'i', and append a 'g'.
//
// Given two strings, compute the edit distance between them.

class Solution {
public:
    int getEditDistance(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }

        for (int j = 0; j <= m; j++) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                }
            }
        }

        return dp[n][m];
    }
};

int main() {
    // Daily Coding Problem: Problem #31 [Easy] - 26/10/25
    Solution s;

    std::cout << "Running Edit Distance Tests...\n\n";

    // Basic Cases
    std::cout << "Test 1: Empty strings\n";
    assert(s.getEditDistance("", "") == 0);
    std::cout << "✓ Passed\n\n";

    std::cout << "Test 2: One empty string\n";
    assert(s.getEditDistance("abc", "") == 3);
    std::cout << "✓ Passed\n\n";

    std::cout << "Test 3: Other empty string\n";
    assert(s.getEditDistance("", "abc") == 3);
    std::cout << "✓ Passed\n\n";

    std::cout << "Test 4: Identical strings\n";
    assert(s.getEditDistance("hello", "hello") == 0);
    std::cout << "✓ Passed\n\n";

    // Single Operation Cases
    std::cout << "Test 5: Single substitution\n";
    assert(s.getEditDistance("cat", "bat") == 1);
    std::cout << "✓ Passed\n\n";

    std::cout << "Test 6: Single insertion\n";
    assert(s.getEditDistance("cat", "cats") == 1);
    std::cout << "✓ Passed\n\n";

    std::cout << "Test 7: Single deletion\n";
    assert(s.getEditDistance("cats", "cat") == 1);
    std::cout << "✓ Passed\n\n";

    // Given Example
    std::cout << "Test 8: Kitten to sitting\n";
    assert(s.getEditDistance("kitten", "sitting") == 3);
    std::cout << "✓ Passed\n\n";

    // Multiple Operations
    std::cout << "Test 9: Multiple substitutions\n";
    assert(s.getEditDistance("abc", "xyz") == 3);
    std::cout << "✓ Passed\n\n";

    std::cout << "Test 10: Mixed operations\n";
    assert(s.getEditDistance("sunday", "saturday") == 3);
    std::cout << "✓ Passed\n\n";

    std::cout << "Test 11: Different lengths\n";
    assert(s.getEditDistance("intention", "execution") == 5);
    std::cout << "✓ Passed\n\n";

    std::cout << "Test 12: Complete replacement\n";
    assert(s.getEditDistance("horse", "ros") == 3);
    std::cout << "✓ Passed\n\n";

    // Edge Cases
    std::cout << "Test 13: Single character strings - same\n";
    assert(s.getEditDistance("a", "a") == 0);
    std::cout << "✓ Passed\n\n";

    std::cout << "Test 14: Single character strings - different\n";
    assert(s.getEditDistance("a", "b") == 1);
    std::cout << "✓ Passed\n\n";

    std::cout << "Test 15: One character vs many\n";
    assert(s.getEditDistance("a", "abcdef") == 5);
    std::cout << "✓ Passed\n\n";

    std::cout << "Test 16: Reversed strings\n";
    assert(s.getEditDistance("abc", "cba") == 2);
    std::cout << "✓ Passed\n\n";

    std::cout << "Test 17: Long identical strings\n";
    assert(s.getEditDistance("abcdefghijklmnop", "abcdefghijklmnop") == 0);
    std::cout << "✓ Passed\n\n";

    // Special Character Cases
    std::cout << "Test 18: Strings with spaces\n";
    assert(s.getEditDistance("hello world", "helloworld") == 1);
    std::cout << "✓ Passed\n\n";

    std::cout << "Test 19: Case sensitivity\n";
    assert(s.getEditDistance("Hello", "hello") == 1);
    std::cout << "✓ Passed\n\n";

    std::cout << "Test 20: Numbers and letters\n";
    assert(s.getEditDistance("abc123", "abc456") == 3);
    std::cout << "✓ Passed\n\n";

    // Performance/Boundary Cases
    std::cout << "Test 21: Moderately long strings\n";
    assert(s.getEditDistance("algorithm", "altruistic") == 6);
    std::cout << "✓ Passed\n\n";

    std::cout << "Test 22: Repeated characters\n";
    assert(s.getEditDistance("aaaa", "aaab") == 1);
    std::cout << "✓ Passed\n\n";

    std::cout << "Test 23: No common characters\n";
    assert(s.getEditDistance("abc", "def") == 3);
    std::cout << "✓ Passed\n\n";

    std::cout << "========================================\n";
    std::cout << "All tests passed successfully! ✓\n";
    std::cout << "========================================\n";

    return 0;
}
