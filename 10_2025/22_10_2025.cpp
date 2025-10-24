#include <cstdlib>
#include <iostream>
#include <stack>
using namespace std;

// Daily Coding Problem: Problem #27 [Easy] - 22/10/25
//
// This problem was asked by Facebook.
// Given a string containing round, curly, and square brackets —
// both opening and closing — determine whether the brackets
// are balanced (i.e., well-formed).
//
// Examples:
//   "([])[]({})"  -> true
//   "([)]"        -> false
//   "((()"        -> false

class Solution {
public:
    bool balancedBrackets(string s) {
        // s must have even size
        if (s.size() % 2 == 1) return false;

        stack<char> letters;
        bool res = true;

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                letters.push(c);
                continue;
            }

            if (letters.empty()) return false;

            char last = letters.top();
            letters.pop();
            if (c == ')') {
                res = res && (last == '(');
            } else if (c == '}') {
                res = res && (last == '{');
            } else {
                res = res && (last == '[');
            }
        }

        return res && letters.empty();
    }
};

int main() {
    // Daily Coding Problem: Problem #27 [Easy] - 22/10/25
    Solution s;
    string s1 = "([])[]({})";
    string s2 = "([)]";
    string s3 = "((()";
    string s4 = "(";
    string s5 = ")())";
    string s6 = "";

    cout << "Expected: 1, Got: " << s.balancedBrackets(s1) << endl;
    cout << "Expected: 0, Got: " << s.balancedBrackets(s2) << endl;
    cout << "Expected: 0, Got: " << s.balancedBrackets(s3) << endl;
    cout << "Expected: 0, Got: " << s.balancedBrackets(s4) << endl;
    cout << "Expected: 0, Got: " << s.balancedBrackets(s5) << endl;
    cout << "Expected: 1, Got: " << s.balancedBrackets(s6) << endl;

    return 0;
}
