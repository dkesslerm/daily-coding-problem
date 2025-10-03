#include <cctype>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    // Daily Coding Problem: Problem #7 [Medium] - 2/10/25
    //
    // This problem was asked by Facebook.
    // Given the mapping:
    //   a = 1, b = 2, ..., z = 26,
    // and an encoded message, count the number of ways
    // it can be decoded.
    //
    // For example, the message '111' would give 3, since
    // it could be decoded as:
    //   'aaa', 'ka', and 'ak'.
    //
    // You can assume that the messages are decodable.
    // For example, '001' is not allowed.

    int numDecodings(string message) {
        int n = message.length();
        if (n == 0) return 0;

        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = (message[0] != '0');

        for (int i = 2; i <= n; i++) {
            if (message[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }
            if (message[i - 1] < '7' && (message[i - 2] == '1' || message[i - 2] == '2')) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[n];
    }

};

int main() {
    Solution s;

    // Daily Coding Problem: Problem #7 [Medium] - 2/10/25
    cout << s.numDecodings("101") << endl;
    cout << s.numDecodings("110") << endl;


    return 0;
}
