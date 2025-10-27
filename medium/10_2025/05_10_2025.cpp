#include <iostream>
#include <chrono>
#include <thread>
#include <functional>
using namespace std;


class Solution {
public:
    // Daily Coding Problem: Problem #10 [Medium] - 5/10/25
    //
    // This problem was asked by Apple.
    // Implement a job scheduler which takes in a function f and
    // an integer n, and calls f after n milliseconds.
    void jobScheduler(function<void()> f, int n) {
        this_thread::sleep_for(chrono::milliseconds(n));
        f();
    }
};

int main() {
    Solution s;

    // Daily Coding Problem: Problem #10 [Medium] - 5/10/25
    function<void()> f = []() {
        cout << "Hello world!" << endl;
    };

    cout << "Waiting..." << endl;
    s.jobScheduler(f, 2000);

    return 0;
}
