#include <iostream>
#include <unordered_map>
#include <random>
using namespace std;

// Daily Coding Problem: Problem #63 [Easy] - 28/11/25
//
// This problem was asked by Microsoft.
// Given a 2D matrix of characters and a target word, write a function that returns
// whether the word can be found in the matrix by going left-to-right, or up-to-down.

// For example, given the following matrix:

// [['F', 'A', 'C', 'I'],
//  ['O', 'B', 'Q', 'P'],
//  ['A', 'N', 'O', 'B'],
//  ['M', 'A', 'S', 'S']]

// and the target word 'FOAM', you should return true, since it's the leftmost column.
// Similarly, given the target word 'MASS', you should return true, since it's the last row.

class Solution {
public:
    bool canBeFound(vector<vector<char>>& matrix, string word) {
        if (word.empty()) return true;
        if (matrix.empty() || matrix[0].empty()) return false;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int length = word.size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (i + length <= rows) {
                    int k = 0;
                    while (k < length && matrix[i + k][j] == word[k]) {
                        k++;
                    }
                    if (k == length) return true;
                }

                if (j + length <= cols) {
                    int k = 0;
                    while (k < length && matrix[i][j + k] == word[k]) {
                        k++;
                    }
                    if (k == length) return true;
                }
            }
        }

        return false;
    }
};

int main() {
    // Daily Coding Problem: Problem #63 [Easy] - 28/11/25
    Solution s;

    vector<vector<char>> matrix = {
        {'F', 'A', 'C', 'I'},
        {'O', 'B', 'Q', 'P'},
        {'A', 'N', 'O', 'B'},
        {'M', 'A', 'S', 'S'}
    };

        string target = "MASS";

    cout << s.canBeFound(matrix, target) << endl;

    return 0;
}
