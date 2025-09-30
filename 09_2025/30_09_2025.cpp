#include <iostream>
using namespace std;

class Solution {
public:
    // Daily Coding Problem: Problem #5 [Medium] - 30/9/25
    // auto parameters in functions are a C++20 feature (compile with -std=c++20 if needed)
    auto cons(auto a, auto b) {
        return [a, b](auto f) {
            return f(a, b);
        };
    }

    auto car(auto pair) {
        return pair([](auto a, auto b) {
            return a;
        });
    }

    auto cdr(auto pair) {
        return pair([](auto a, auto b) {
            return b;
        });
    }
};

int main() {
    Solution s;

    // Daily Coding Problem: Problem #5 [Medium] - 30/9/25
        auto pair = s.cons(1, "puerta");
        cout << "First element: " << s.car(pair) << endl;
        cout << "Second element: " << s.cdr(pair) << endl;

    return 0;
}
