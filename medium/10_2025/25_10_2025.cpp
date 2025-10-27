#include <iostream>
#include <vector>
using namespace std;

// Daily Coding Problem: Problem #30 [Medium] - 25/10/25
//
// This problem was asked by Facebook.
// You are given an array of non-negative integers that represents a
// two-dimensional elevation map. Each element is a unit-width wall,
// and the integer value is its height. Suppose it rains and all spots
// between two walls get filled with water.
//
// Compute how many units of water remain trapped on the map.
// The solution should run in O(N) time and use O(1) extra space.
//
// Examples:
//  - Input: [2, 1, 2]
//    Explanation: 1 unit of water is trapped in the middle.
//    Output: 1
//
//  - Input: [3, 0, 1, 3, 0, 5]
//    Explanation:
//      * index 0 traps 3 units,
//      * index 1 traps 2 units,
//      * index 3 traps 3 units.
//      (We cannot trap 5 at index 5 because water would run off to the left.)
//    Total trapped water = 8
//

class Solution {
public:
    int trappedWater(vector<int> walls) {
        if (walls.size() < 3) return 0;

        int water = 0;
        int left = 0;
        int right = walls.size() - 1;
        int leftMax = walls[0];
        int rightMax = walls.back();

        while (left < right) {
            if (leftMax < rightMax) {
                left++;
                leftMax = max(leftMax, walls[left]);
                water += leftMax - walls[left];
            } else {
                right--;
                rightMax = max(rightMax, walls[right]);
                water += rightMax - walls[right];
            }
        }

        return water;
    }

    // Follow-up: What if we also wanted to know what indices trap water? How would
    // space complexity change?
    pair<int, vector<int>> trappedWaterWithIndices(vector<int> walls) {
        if (walls.size() < 3) return {0, {}};

        int water = 0;
        int waterNow = 0;
        int left = 0;
        int right = walls.size() - 1;
        int leftMax = walls[0];
        int rightMax = walls.back();
        vector<int> indices; // Space complexity would now be O(n), n = columns

        while (left < right) {
            if (leftMax < rightMax) {
                left++;
                leftMax = max(leftMax, walls[left]);
                waterNow = leftMax - walls[left];
                water += waterNow;
                if (waterNow > 0) {
                    indices.push_back(left);
                }
            } else {
                right--;
                rightMax = max(rightMax, walls[right]);
                waterNow = rightMax - walls[right];
                water += waterNow;
                if (waterNow > 0) {
                    indices.push_back(right);
                }
            }
        }

        return {water, indices};
    }
};

int main() {
    // Daily Coding Problem: Problem #30 [Medium] - 25/10/25
    Solution s;
    vector<int> walls = {3, 0, 1, 3, 0, 5};

    cout << s.trappedWater(walls) << endl;

    pair<int, vector<int>> result = s.trappedWaterWithIndices(walls);
    cout << result.first << endl;
    for (int index : result.second) {
        cout << index << " ";
    }
    cout << "\b";

    return 0;
}
