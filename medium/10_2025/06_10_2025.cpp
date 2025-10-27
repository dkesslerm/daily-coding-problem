#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord = false;
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* current = root;
        for (char c : word) {
            if (!current->children[c]) {
                current->children[c] = new TrieNode();
            }
            current = current->children[c];
        }
        current->isEndOfWord = true;
    }

    bool search(string word) {
        TrieNode* current = root;
        for (char c : word) {
            if (!current->children[c]) {
                return false;
            }
            current = current->children[c];
        }

        return current->isEndOfWord;
    }

    bool startsWith(string prefix) {
        TrieNode* current = root;
        for (char c : prefix) {
            if (!current->children[c]) {
                return false;
            }
            current = current->children[c];
        }

        return true;
    }

    void collectWords(TrieNode* current, string prefix, vector<string>& result) {
        if (!current) return;

        if (current->isEndOfWord) {
            result.push_back(prefix);
        }

        for (auto it : current->children) {
            collectWords(it.second, prefix + it.first, result);
        }
    }

    vector<string> getWordsWithPrefix(string prefix) {
        vector<string> res;
        TrieNode* current = root;

        for (char c : prefix) {
            if (!current->children[c]) {
                return {};
            }
            current = current->children[c];
        }

        collectWords(current, prefix, res);

        return res;
    }
};



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

    vector<string> autocomplete(vector<string> dictionary, string query) {
        Trie t;
        for (string s : dictionary) {
            t.insert(s);
        }
        return t.getWordsWithPrefix(query);
    }
};

int main() {
    Solution s;

    // Daily Coding Problem: Problem #11 [Medium] - 6/10/25
    vector<string> dict = {"apple", "application", "apply", "app",
            "banana", "band", "can", "cat", "catch"};
    string query = "cat";
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
