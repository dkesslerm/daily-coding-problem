#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Daily Coding Problem: Problem #2 [Hard] - 27/9/25
    vector<int> multipliedArray(vector<int>& input) {
        // int multiplication = 1;
        // for (int i : input) {
        //     multiplication *= i;
        // }

        // vector<int> res(input.size(), multiplication);
        // for (int i = 0; i < input.size(); i++) {
        //     res[i] /= input[i];
        // }

        // return res;

        // Follow-up: what if you can't use division?

        int n = input.size();
        vector<int> res(n, 1);

        for (int i = 1; i < n; i++) {
            res[i] = res[i - 1] * input[i - 1];
        }

        int right = 1;
        for (int i = n - 1; i >= 0; i--) {
            res[i] *= right;
            right *= input[i];
        }

        return res;
    }
};

int main() {
    Solution s;

    // Daily Coding Problem: Problem #2 [Hard] - 27/9/25
    vector<int> input = {1, 2, 3, 4, 5};
    input = s.multipliedArray(input);

    for (int i : input) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
