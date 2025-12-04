#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

// Daily Coding Problem: Problem #53 [Medium] - 18/11/25
//
// This problem was asked by Apple.
//
// Implement a queue using two stacks.
// Recall that a queue is a FIFO (first-in, first-out) data
// structure with the following methods: enqueue, which
// inserts an element into the queue, and dequeue, which removes it.

class TwoStackQueue {
private:
    stack<int> s1, s2;
public:
    void enqueue(int val) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(val);
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int dequeue() {
        if (s1.empty()) return -1;
        int res = s1.top();
        s1.pop();
        return res;
    }
};

int main() {
    // Daily Coding Problem: Problem #53 [Medium] - 18/11/25
    TwoStackQueue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << "Expected: 1, got: " << q.dequeue() << endl;
    cout << "Expected: 2, got: " << q.dequeue() << endl;
    cout << "Expected: 3, got: " << q.dequeue() << endl;

    return 0;
}
