#include <cctype>
#include <iostream>
#include <string>
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
        int befprev = 1;
        int prev = (message[0] != '0');

        for (int i = 2; i <= n; i++) {
            int current = 0;

            if (message[i - 1] != '0') {
                current += prev;
            }
            int twoDigit = (message[i - 2] - '0') * 10 + (message[i - 1] - '0');
            if (twoDigit >= 10 && twoDigit <= 26) {
                current += befprev;
            }

            befprev = prev;
            prev = current;
        }

        return prev;
    }

};

int main() {
    Solution s;

    // Daily Coding Problem: Problem #7 [Medium] - 2/10/25
    cout << s.numDecodings("101") << endl;
    cout << s.numDecodings("110") << endl;
    cout << s.numDecodings("2611055971756562") << endl;


    return 0;
}
