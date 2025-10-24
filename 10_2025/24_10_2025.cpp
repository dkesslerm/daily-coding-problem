#include <cctype>
#include <cstdlib>
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

// Daily Coding Problem: Problem #28 [Medium] - 23/10/25
//
// This problem was asked by Amazon.
// Run-length encoding is a fast and simple method of encoding
// strings. The basic idea is to represent repeated successive
// characters as a single count and character. For example, the
// string "AAAABBBCCDAA" would be encoded as "4A3B2C1D2A".
//
// Implement run-length encoding and decoding.
//
// Assumptions:
// - The string to be encoded has no digits and consists only of
//   alphabetic characters.
// - The string to be decoded is valid.
class Solution {
public:
    string encodeRunLengthString(string s) {
        string res = "";
        int count = 1;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (i < n && s[i] == s[i + 1]) {
                count++;
            } else {
                res += to_string(count) + s[i];
                count = 1;
            }
        }

        return res;
    }

    string decodeRunLengthString(string s) {
        string res = "";
        int n = s.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            int iter = i;
            while (isdigit(s[iter])) {
                iter++;
            }
            int digits = iter - i;

            if (isdigit(s[i])) {
                count = stoi(s.substr(i, digits));
            }
            while (count > 0) {
                res += s[i + digits];
                count--;
            }

            if (digits > 1) i += digits;
        }

        return res;
    }
};

int main() {
    // Daily Coding Problem: Problem #28 [Medium] - 23/10/25
    Solution s;
    string s1 = "AAAAAAAAAAABBBCDDAF";
    string s2 = s.encodeRunLengthString(s1);
    cout << s2 << endl;
    cout << s.decodeRunLengthString(s2) << endl;

    return 0;
}
