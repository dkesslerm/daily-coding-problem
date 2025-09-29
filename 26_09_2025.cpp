#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    // Daily Coding Problem: Problem #1 [Easy] - 26/9/25
    bool canAddUpToNumber(vector<int>& numbers, int k) {
        if (numbers.size() == 1) return false;
        unordered_map<int, int> remains;
        for (int n : numbers) {
            remains[n] = k - n;
        }

        for (int i = 0; i < numbers.size(); i++) {
            if (remains.find(k - numbers[i]) != remains.end()) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    Solution s;

    // Daily Coding Problem: Problem #1 [Easy] - 26/9/25
    vector<int> numbers = {3, 3, 3, 3};
    int k = 6;
    bool result = s.canAddUpToNumber(numbers, k);
    cout << result << endl;

    return 0;
}
