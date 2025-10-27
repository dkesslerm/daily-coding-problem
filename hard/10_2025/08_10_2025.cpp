#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Daily Coding Problem: Problem #13 [Hard] - 8/10/25
    // This problem was asked by Amazon.

    // Given an integer k and a string s,
    // find the length of the longest substring
    // that contains at most k distinct characters.

    // For example, given s = "abcba" and k = 2,
    // the longest substring with k distinct
    // characters is "bcb".

    int distinctSubstringLength(int k, string s) {
        int left = 0, maxLength = 0;
        unordered_map<char, int> appearances;

        for (int right = 0; right < s.length(); right++) {
            appearances[s[right]]++;

            while (appearances.size() > k) {
                appearances[s[left]]--;
                if (appearances[s[left]] == 0) {
                    appearances.erase(s[left]);
                }
                left++;
            }

            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

int main() {
    Solution s;

    // Daily Coding Problem: Problem #13 [Hard] - 8/10/25
    string str = "abcba";
    int k = 2;

    cout << s.distinctSubstringLength(k, str) << endl;

    return 0;
}
