#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cassert>
using namespace std;

// Daily Coding Problem: Problem #43 [Easy] - 08/11/25
//
// This problem was asked by Amazon.
// Implement a stack that has the following methods:
//
//   - push(val), which pushes an element onto the stack
//   - pop(), which pops off and returns the topmost element of the stack.
//     If there are no elements in the stack, then it should throw an error or return null.
//   - max(), which returns the maximum value in the stack currently.
//     If there are no elements in the stack, then it should throw an error or return null.
//
// Each method should run in constant time.

class MaxStack {
private:
    // stack<pair<int, int>> s;
    stack<int> sEff;
    int currMax;
public:
    void push(int val) {
        // if (s.empty()) {
        //     s.push({val, val});
        // } else {
        //     int maxVal = max(val, s.top().second);
        //     s.push({val, maxVal});
        // }
        if (val <= currMax) {
            sEff.push(val);
        } else {
            sEff.push(2*val - currMax);
            currMax = val;
        }
    }

    int pop() {
        // assert(!s.empty());
        assert(!sEff.empty());

        // int val = s.top().first;
        // s.pop();

        int val = sEff.top();
        sEff.pop();
        if (val <= currMax) {
            return val;
        } else {
            int maxVal = currMax;
            currMax = 2 * currMax - val;
            return maxVal;
        }
    }

    int getMax() {
        assert(!sEff.empty());

        return currMax;
    }
};

int main() {
    // Daily Coding Problem: Problem #43 [Easy] - 08/11/25
    MaxStack s;

    s.push(18);
    s.push(19);
    s.push(29);
    s.push(15);
    cout << s.pop() << endl;
    cout << s.getMax() << endl;
    s.push(16);
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.getMax() << endl;

    return 0;
}
