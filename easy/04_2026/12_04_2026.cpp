#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Daily Coding Problem: Problem #159 [Easy] - 12/04/26
//
// This problem was asked by Google.
// Given a string, return the first recurring character in it,
// or null if there is no recurring character.
// 
// For example, given the string "acbbac", return "b". 
// Given the string "abcdef", return null.

class Solution {
public:
    char findFirstRecurringChar(string s) {
        unordered_map<char, int> apps;
        int mapSize = 0;
        int prevMapSize = 0;
        for (char c : s) {
            apps[c]++;
            mapSize = apps.size();
            if (mapSize != prevMapSize + 1) return c;
            prevMapSize = mapSize;
        }
        
        return '.';
    }
};

int main() {
    // Daily Coding Problem: Problem #38 [Hard] - 02/11/25
    Solution s;

    cout << s.findFirstRecurringChar("abcaef") << endl;

    return 0;
}
