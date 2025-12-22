#include <iostream>
#include <stack>
#include <algorithm>
#include <sstream>
using namespace std;

// Daily Coding Problem: Problem #57 [Medium] - 22/11/25
//
// This problem was asked by Amazon.
//
// Given a string s and an integer k, break up the string into multiple lines
// such that each line has a length of k or less. You must break it up so that
// words don't break across lines. Each line has to have the maximum possible amount of words.
// If there's no way to break the text up, then return null.
//
// For example, given the string "the quick brown fox jumps over the lazy dog" and k = 10,
// you should return: ["the quick", "brown fox", "jumps over", "the lazy", "dog"].
// No string in the list has a length of more than 10.
//
// You can assume that there are no spaces at the ends of the string and that there is
// exactly one space between each word.

class Solution {
public:
    vector<string> breakUpString(string s, int k) {
        vector<string> res;
        stringstream ss(s);
        string line = "", word = "";
        while (getline(ss, word, ' ')) {
            if (word.size() > k) {
                return {};
            }

            if (line.empty()) {
                line += word;
            } else {
                if (line.size() + word.size() + 1 <= k) {
                    line += " " + word;
                } else {
                    res.push_back(line);
                    line = word;
                }
            }
        }

        if (!line.empty()) {
            res.push_back(line);
        }

        return res;
    }
};

int main() {
    // Daily Coding Problem: Problem #57 [Medium] - 22/11/25
    Solution s;

    // Test 1 — Given example
    {
        string t = "the quick brown fox jumps over the lazy dog";
        int k = 10;
        cout << "\nTest 1\n";
        for (const string& line : s.breakUpString(t, k)) {
            cout << line << endl;
        }
    }

    // Test 2 — Exact fit per line
    {
        string t = "hello world here";
        int k = 5;
        cout << "\nTest 2\n";
        for (const string& line : s.breakUpString(t, k)) {
            cout << line << endl;
        }
    }

    // Test 3 — Single long word (null)
    {
        string t = "supercalifragilisticexpialidocious";
        int k = 10;
        cout << "\nTest 3\n";
        auto res = s.breakUpString(t, k);
        cout << (res.empty() ? "null" : "ERROR") << endl;
    }

    // Test 4 — Word longer than k among others (null)
    {
        string t = "short words extraordinary short";
        int k = 10;
        cout << "\nTest 4\n";
        auto res = s.breakUpString(t, k);
        cout << (res.empty() ? "null" : "ERROR") << endl;
    }

    // Test 5 — k = 1, all single-character words
    {
        string t = "a b c d";
        int k = 1;
        cout << "\nTest 5\n";
        for (const string& line : s.breakUpString(t, k)) {
            cout << line << endl;
        }
    }

    // Test 6 — k too small to fit spaces (null)
    {
        string t = "a b";
        int k = 0;
        cout << "\nTest 6\n";
        auto res = s.breakUpString(t, k);
        cout << (res.empty() ? "null" : "ERROR") << endl;
    }

    // Test 7 — Single word fits exactly
    {
        string t = "hello";
        int k = 5;
        cout << "\nTest 7\n";
        for (const string& line : s.breakUpString(t, k)) {
            cout << line << endl;
        }
    }

    // Test 8 — Single word shorter than k
    {
        string t = "hello";
        int k = 10;
        cout << "\nTest 8\n";
        for (const string& line : s.breakUpString(t, k)) {
            cout << line << endl;
        }
    }

    // Test 9 — Greedy packing check
    {
        string t = "a bb ccc dddd eeeee";
        int k = 7;
        cout << "\nTest 9\n";
        for (const string& line : s.breakUpString(t, k)) {
            cout << line << endl;
        }
    }

    // Test 10 — Large k, everything fits
    {
        string t = "one two three four five";
        int k = 100;
        cout << "\nTest 10\n";
        for (const string& line : s.breakUpString(t, k)) {
            cout << line << endl;
        }
    }

    // Test 11 — Minimal input
    {
        string t = "a";
        int k = 1;
        cout << "\nTest 11\n";
        for (const string& line : s.breakUpString(t, k)) {
            cout << line << endl;
        }
    }

    // Test 12 — Tight packing edge
    {
        string t = "ab cd ef gh";
        int k = 5;
        cout << "\nTest 12\n";
        for (const string& line : s.breakUpString(t, k)) {
            cout << line << endl;
        }
    }

    return 0;
}
