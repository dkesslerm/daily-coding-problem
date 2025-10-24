#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

// Daily Coding Problem: Problem #28 [Medium] - 23/10/25
//
// This problem was asked by Palantir.
// Write an algorithm to justify text. Given a sequence of words
// and an integer line length k, return a list of strings which
// represents each line, fully justified.
//
// More specifically:
// - You should have as many words as possible in each line.
// - There should be at least one space between each word.
// - Pad extra spaces when necessary so that each line has exactly
//   length k.
// - Spaces should be distributed as equally as possible, with the
//   extra spaces (if any) distributed starting from the left.
//
// If you can only fit one word on a line, pad the right-hand side
// with spaces so the line length equals k.
//
// Each word is guaranteed not to be longer than k.
//
// Example:
// Given the list of words:
//   ["the", "quick", "brown", "fox", "jumps", "over", "the",
//    "lazy", "dog"]
// and k = 16, you should return the following lines:
//
//   ["the  quick brown",  // 1 extra space on the left
//    "fox  jumps  over",  // 2 extra spaces distributed evenly
//    "the   lazy   dog"]  // 4 extra spaces distributed evenly

class Solution {
public:
    vector<string> justifyText(vector<string> words, int k) {
        vector<string> result;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int lineSize = words[i].size();
            int j = i + 1;

            // Check how many words fit in this line
            while (j < n && lineSize + 1 + words[j].size() <= k) {
                lineSize += words[j].size() + 1;
                j++;
            }

            int numWords = j - i;
            int totalChars = 0;
            for (int p = i; p < j; p++) {
                totalChars += words[p].size();
            }

            int totalSpaces = k - totalChars;
            string line = "";

            if (numWords == 1) {
                line = words[i] + string(totalSpaces, ' ');
            } else {
                int gaps = numWords - 1;
                int spacePerGap = totalSpaces / gaps;
                int extraSpaces = totalSpaces % gaps;

                for (int p = i; p < j; p++) {
                    line += words[p];
                    if (p < j - 1) {
                        int spaces = spacePerGap + (extraSpaces-- > 0 ? 1 : 0);
                        line += string(spaces, ' ');
                    }
                }
            }

            result.push_back(line);
            i = j;
        }

        return result;
    }
};

int main() {
    // Daily Coding Problem: Problem #28 [Medium] - 23/10/25
    Solution s;
    vector<string> words = {"the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};
    int k = 16;

    for (string s : s.justifyText(words, k)) {
        for (char c : s) {
            cout << c;
        }
        cout << endl;
    }

    return 0;
}
