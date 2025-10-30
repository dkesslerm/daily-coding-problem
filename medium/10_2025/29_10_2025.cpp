#include <iostream>
#include <vector>
using namespace std;

// Daily Coding Problem: Problem #34 [Medium] - 29/10/25
//
// This problem was asked by Quora.
// Given a string, find the palindrome that can be made by inserting the
// fewest number of characters as possible anywhere in the word. If there
// is more than one palindrome of minimum length that can be made, return
// the lexicographically earliest one (the first one alphabetically).
//
// For example, given the string "race", you should return "ecarace", since
// we can add three letters to it (which is the smallest amount to make a
// palindrome). There are seven other palindromes that can be made from
// "race" by adding three letters, but "ecarace" comes first alphabetically.
//
// As another example, given the string "google", you should return
// "elgoogle".

class Solution {
public:
    string makePalindrome(string s) {
        int n = s.size();
        // dp[i][j] indicates the smallest palindrome starting in i that ends in j
        vector<vector<string>> dp(n, vector<string>(n));

        // A string starting and ending in the same spot is palindrome
        for (int i = 0; i < n; i++) {
            dp[i][i] = s[i];
        }

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) { // if the chars are the same, it stays a palindrome
                    dp[i][j] = s[i] + dp[i + 1][j - 1] + s[j];
                } else {
                    string a = s[i] + dp[i + 1][j] + s[i]; // rar
                    string b = s[j] + dp[i][j - 1] + s[j]; // ara

                    if (a.size() < b.size()) { // we want the smallest one
                        dp[i][j] = a;
                    } else if (b.size() < a.size()) {
                        dp[i][j] = b;
                    } else { // first one alphabetically
                        dp[i][j] = min(a, b);
                    }
                }
            }
        }

        // We return the minimum palindrome of size n
        return dp[0][n - 1];
    }
};

int main() {
    // Daily Coding Problem: Problem #34 [Medium] - 29/10/25
    Solution s;

    cout << s.makePalindrome("race") << endl;

    cout << s.makePalindrome("google") << endl;
    return 0;
}
