#include <cctype>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    // Daily Coding Problem: Problem #11 [Medium] - 6/10/25

    // This problem was asked by Twitter.
    // Implement an autocomplete system. That is, given a query string s
    // and a set of all possible query strings, return all strings in the
    // set that have s as a prefix.

    // For example, given the query string de and the set of strings
    // [dog, deer, deal], return [deer, deal].

    // Hint: Try preprocessing the dictionary into a more efficient data
    // structure to speed up queries.

    // This hint tells us to use a Trie, but I'm not going to.
    // This works fine, but it's not as scalable as a Trie.
    vector<string> autocomplete(vector<string> dictionary, string query) {
        vector<string> res;
        for (string s : dictionary) {
            if (s.substr(0, query.size()) == query) {
                res.push_back(s);
            }
        }

        return res;
    }
};

int main() {
    Solution s;

    // Daily Coding Problem: Problem #11 [Medium] - 6/10/25
    vector<string> dict = {"dog", "deer", "deal"};
    string query = "d";
    vector<string> res = s.autocomplete(dict, query);
    cout << "[";
    for (string s : res) {
        for (char c : s) {
            cout << c;
        }
        cout << ", ";
    }
    cout << "\b\b]" << endl;

    return 0;
}
