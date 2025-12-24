#include <iostream>
#include <numeric>
#include <stack>
#include <algorithm>
#include <sstream>
using namespace std;

// Daily Coding Problem: Problem #60 [Medium] - 25/11/25
//
// This problem was asked by Google.
// Implement integer exponentiation. That is, implement the
// pow(x, y) function, where x and y are integers and returns x^y.
//
// Do this faster than the naive method of repeated multiplication.
//
// For example, pow(2, 10) should return 1024.

class Solution {
public:
    int recursivePower(int x, int y) {
        if (y == 0) return 1;
        if (y == 1) return x;

        if (y % 2 == 0) {
            return recursivePower(x * x, y / 2);
        } else {
            return x * recursivePower(x * x, (y - 1) / 2);
        }
    }

    int iterativePower(int x, int y) {
        int res = 1;
        while (y > 0) {
            if (y % 2 == 1) {
                res *= x;
            }

            x *= x;
            y /= 2;
        }

        return res;
    }
};

int main() {
    // Daily Coding Problem: Problem #60 [Medium] - 25/11/25
    Solution s;

    cout << s.recursivePower(2, 10) << endl;
    cout << s.iterativePower(2, 10) << endl;

    return 0;
}
