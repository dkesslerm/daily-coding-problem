#include <iostream>
#include <vector>
using namespace std;

// Daily Coding Problem: Problem #35 [Hard] - 30/10/25
//
// This problem was asked by Google.
// Given an array of strictly the characters 'R', 'G', and 'B',
// segregate the values of the array so that all the Rs come first,
// the Gs come second, and the Bs come last.
// You can only swap elements of the array.
//
// Do this in linear time and in-place.
//
// For example, given the array
// ['G', 'B', 'R', 'R', 'B', 'R', 'G'],
// it should become
// ['R', 'R', 'R', 'G', 'G', 'B', 'B'].

class Solution {
public:
    void sortRGB(vector<char>& input) {
        int n = input.size();
        int nextR = 0, curr = 0, nextB = n - 1;

        while (curr <= nextB) {
            if (input[curr] == 'R') {
                swap(input[curr], input[nextR]);
                nextR++;
                curr++;
            } else if (input[curr] == 'G') {
                curr++;
            } else {
                swap(input[curr], input[nextB]);
                nextB--;
            }
        }
    }
};

int main() {
    // Daily Coding Problem: Problem #35 [Hard] - 30/10/25
    Solution s;

    vector<char> input = {'G', 'B', 'R', 'R', 'B', 'R', 'G'};
    s.sortRGB(input);
    for (char c : input) {
        cout << c;
    }
    cout << endl;

    return 0;
}
