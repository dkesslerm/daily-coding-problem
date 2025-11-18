#include <iostream>
#include <random>
#include <map>
using namespace std;

// Daily Coding Problem: Problem #45 [Easy] - 10/11/25
//
// This problem was asked by Two Sigma.
// Using a function rand5() that returns an integer from 1 to 5
// (inclusive) with uniform probability, implement a function
// rand7() that returns an integer from 1 to 7 (inclusive).

class Solution {
public:
    int rand5() {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distr(1, 5);

        return distr(gen);
    }

    int rand7() {
        int num;

        while (true) {
            num = (rand5() - 1) * 5 + rand5();

            if (num <= 21) {
                break;
            }
        }

        return (num - 1) % 7 + 1;
    }
};

int main() {
    // Daily Coding Problem: Problem #45 [Easy] - 10/11/25
    Solution s;

    // Test the distribution (AI generated)
    map<int, int> frequency;
    int trials = 70000;

    cout << "Running " << trials << " trials...\n\n";

    for (int i = 0; i < trials; i++) {
        frequency[s.rand7()]++;
    }

    cout << "Distribution of rand7():\n";
    cout << "Value | Count | Percentage\n";
    cout << "------|-------|------------\n";

    for (auto& [value, count] : frequency) {
        double percentage = (count * 100.0) / trials;
        cout << "  " << value << "   | " << count << " | "
                << percentage << "%\n";
    }

    cout << "\nExpected: ~14.29% for each value (1/7)\n";

    return 0;
}
