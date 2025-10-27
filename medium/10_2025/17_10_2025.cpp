#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Daily Coding Problem: Problem #22 [Medium] - 17/10/25
//
// This problem was asked by Microsoft.
// Given a dictionary of words and a string made up of those words (no spaces),
// return the original sentence in a list. If there is more than one possible reconstruction, return any of them.
// If there is no possible reconstruction, then return null.

// For example, given:
// The set of words 'quick', 'brown', 'the', 'fox',
// and the string "thequickbrownfox",
// you should return ['the', 'quick', 'brown', 'fox'].

// Given the set of words 'bed', 'bath', 'bedbath', 'and', 'beyond',
// and the string "bedbathandbeyond",
// return either ['bed', 'bath', 'and', 'beyond] or ['bedbath', 'and', 'beyond'].

class Solution {
public:
    vector<string> reconstructSentence(vector<string> dict, string sentence) {
        vector<string> reconstruction;
        string word = "";
        for (char c : sentence) {
            word += c;
            if (find(dict.begin(), dict.end(), word) != dict.end()) {
                reconstruction.push_back(word);
                word = "";
            }
        }

        return reconstruction;
    }
};

int main() {
    // Daily Coding Problem: Problem #22 [Medium] - 17/10/25
    Solution s;

    vector<string> dict1 = {"quick", "brown", "the", "fox"};
    string sentence1 = "thequickbrownfox";
    vector<string> reconstruction1 = s.reconstructSentence(dict1, sentence1);

    vector<string> dict2 = {"bed", "bath", "bedbath", "and", "beyond"};
    string sentence2 = "bedbathandbeyond";
    vector<string> reconstruction2 = s.reconstructSentence(dict2, sentence2);

    for (string s : reconstruction2) {
        cout << s << " ";
    }

    return 0;
}
