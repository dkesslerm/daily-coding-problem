#include <iostream>
#include <vector>
using namespace std;

// Daily Coding Problem: Problem #40 [Hard] - 05/11/25
//
// This problem was asked by Google.
// Given an array of integers where every integer occurs three times
// except for one integer, which only occurs once, find and return
// the non-duplicated integer.
//
// For example, given [6, 1, 3, 3, 3, 6, 6], return 1.
// Given [13, 19, 13, 13], return 19.
//
// Do this in O(N) time and O(1) space.

// This would be easy if we didn't have the O(1) space constraint
// I've implemented a O(32N) time and O(1) space, that still is linear time.
class Solution {
public:
    int findSingleNumber(vector<int>& v) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            int bitSum = 0;
            for (int num : v) {
                if (num & (1 << i)) {
                    bitSum++;
                }
            }

            if (bitSum % 3 != 0) {
                res |= (1 << i);
            }
        }

        return res;
    }
};

int main() {
    // Daily Coding Problem: Problem #40 [Hard] - 05/11/25
    Solution s;

    vector<int> v1 = {6, 1, 3, 3, 3, 6, 6};
    cout << "Input: [6, 1, 3, 3, 3, 6, 6]" << endl;
    cout << "Output: " << s.findSingleNumber(v1) << endl << endl;

    vector<int> v2 = {13, 19, 13, 13};
    cout << "Input: [13, 19, 13, 13]" << endl;
    cout << "Output: " << s.findSingleNumber(v2) << endl << endl;
    return 0;
}
