#include <iostream>
#include <deque>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Daily Coding Problem: Problem #54 [Hard] - 19/11/25
//
// This problem was asked by Dropbox.
// Sudoku is a puzzle where you're given a partially-filled
// 9 by 9 grid with digits. The objective is to fill the grid
// with the constraint that every row, column, and box (3 by 3 subgrid)
// must contain all of the digits from 1 to 9.
//
// Implement an efficient sudoku solver.

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    };

    bool isValid(vector<vector<char>>& board, char num, int row, int col) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == num || board[i][col] == num) {
                return false;
            }
        }

        int boxRowStart = (row / 3) * 3;
        int boxColStart = (col / 3) * 3;

        for (int r = 0; r < 3; r++) {
            for (int c = 0; c < 3; c++) {
                if (board[boxRowStart + r][boxColStart + c] == num) {
                    return false;
                }
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] != '.') continue;
                for (char num = '1'; num <= '9'; num++) {
                    if (isValid(board, num, row, col)) {
                        board[row][col] = num;
                        if (solve(board)) return true;
                        board[row][col] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    }


};

int main() {
    // Daily Coding Problem: Problem #54 [Hard] - 19/11/25
    Solution s;
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    vector<vector<char>> solved = {
        {'5','3','4','6','7','8','9','1','2'},
        {'6','7','2','1','9','5','3','4','8'},
        {'1','9','8','3','4','2','5','6','7'},
        {'8','5','9','7','6','1','4','2','3'},
        {'4','2','6','8','5','3','7','9','1'},
        {'7','1','3','9','2','4','8','5','6'},
        {'9','6','1','5','3','7','2','8','4'},
        {'2','8','7','4','1','9','6','3','5'},
        {'3','4','5','2','8','6','1','7','9'}
    };

    s.solveSudoku(board);

    cout << "Expected: " << endl;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << solved[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << "Got: " << endl;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
