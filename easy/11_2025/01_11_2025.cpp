#include <iostream>
#include <vector>
using namespace std;

// Daily Coding Problem: Problem #37 [Easy] - 01/11/25
//
// This problem was asked by Google.
// The power set of a set is the set of all its subsets.
// Write a function that, given a set, generates its power set.

// For example, given the set {1, 2, 3}, it should return:
// {{}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}}.

// You may also use a list or array to represent a set.
class Solution {
public:
    vector<vector<int>> generatePowerSet(vector<int> set) {
        vector<vector<int>> powerSet;
        int n = set.size();

        // 1 << n is the same as pow(2, n) which is the size of
        // a power set of a set of size n
        for (int i = 0; i < (1 << n); i++) {
            vector<int> aux;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) { // Each number can be either picked or not
                    aux.push_back(set[j]);
                }
            }
            powerSet.push_back(aux);
        }

        return powerSet;
    }
};

int main() {
    // Daily Coding Problem: Problem #37 [Easy] - 01/11/25
    Solution s;

    vector<int> set = {1, 2, 3, 4};
    for (vector<int> v : s.generatePowerSet(set)) {
        if (v.size() == 0) {
            cout << "[]" << endl;
            continue;
        };
        cout << "[";
        for (int n : v) {
            cout << n << " ";
        }
        cout << "\b]" << endl;
    }

    return 0;
}
