#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// Daily Coding Problem: Problem #21 [Easy] - 16/10/25
//
// This problem was asked by Snapchat.
// Problem:
// Given an array of time intervals (start, end) for classroom lectures
// (possibly overlapping), find the minimum number of rooms required.
//
// Example:
// Input: [(30, 75), (0, 50), (60, 150)]
// Output: 2

class Solution {
public:
    int numRoomsRequired(vector<pair<int, int>> lectures) {
        sort(lectures.begin(), lectures.end(), [](pair<int, int>& a, pair<int, int>& b){
            if (a.first == b.first) return a.second < b.second;
            else return a.first < b.first;
        });

        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (pair<int, int> p : lectures) {
            if (!minHeap.empty() && minHeap.top() <= p.first) {
                minHeap.pop();
            }
            minHeap.push(p.second);
        }

        return minHeap.size();
    }
};

int main() {
    // Daily Coding Problem: Problem #21 [Easy] - 16/10/25
    Solution s;

    // Example from prompt
    vector<pair<int, int>> lectures = {{30, 75}, {0, 50}, {60, 150}};

    // Test cases
    vector<pair<int, int>> t1 = {{0, 10}};  // single interval
    vector<pair<int, int>> t2 = {{0, 10}, {20, 30}, {40, 50}};  // disjoint
    vector<pair<int, int>> t3 = {{0, 50}, {10, 60}, {20, 70}, {30, 80}};  // full overlap
    vector<pair<int, int>> t4 = {{0, 10}, {10, 20}, {20, 30}};  // touching boundaries
    vector<pair<int, int>> t5 = {{0, 100}, {10, 20}, {30, 40}, {50, 60}};  // nested
    vector<pair<int, int>> t6 = {{5, 10}, {0, 30}, {15, 20}, {35, 40}};  // mixed overlaps
    vector<pair<int, int>> t7 = {{0, 100}, {1, 2}, {3, 4}, {5, 6}, {7, 8}};  // one long + shorts
    vector<pair<int, int>> t8 = {{0, 10}, {0, 10}, {0, 10}, {0, 10}, {0, 10}};  // identical
    vector<pair<int, int>> t9 = {{0, 30}, {5, 10}, {15, 20}, {30, 40}};  // overlap + touch
    vector<pair<int, int>> t10 = {{60, 150}, {0, 50}, {30, 75}};  // out-of-order

    cout << "Expected 2, Got " << s.numRoomsRequired(lectures) << endl;
    cout << "Expected 1, Got " << s.numRoomsRequired(t1) << endl;
    cout << "Expected 1, Got " << s.numRoomsRequired(t2) << endl;
    cout << "Expected 4, Got " << s.numRoomsRequired(t3) << endl;
    cout << "Expected 1, Got " << s.numRoomsRequired(t4) << endl;
    cout << "Expected 2, Got " << s.numRoomsRequired(t5) << endl;
    cout << "Expected 2, Got " << s.numRoomsRequired(t6) << endl;
    cout << "Expected 2, Got " << s.numRoomsRequired(t7) << endl;
    cout << "Expected 5, Got " << s.numRoomsRequired(t8) << endl;
    cout << "Expected 2, Got " << s.numRoomsRequired(t9) << endl;
    cout << "Expected 2, Got " << s.numRoomsRequired(t10) << endl;

    return 0;
}
