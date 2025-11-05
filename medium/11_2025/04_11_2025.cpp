#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Daily Coding Problem: Problem #39 [Medium] - 04/11/25
//
// This problem was asked by Dropbox.
// Conway's Game of Life takes place on an infinite two-dimensional board
// of square cells. Each cell is either dead or alive, and at each tick,
// the following rules apply:
//
//     Any live cell with less than two live neighbours dies.
//     Any live cell with two or three live neighbours remains living.
//     Any live cell with more than three live neighbours dies.
//     Any dead cell with exactly three live neighbours becomes a live cell.
//
// A cell neighbours another cell if it is horizontally, vertically, or
// diagonally adjacent.
//
// Implement Conway's Game of Life. It should be able to be initialized
// with a starting list of live cell coordinates and the number of steps
// it should run for. Once initialized, it should print out the board
// state at each step. Since it's an infinite board, print out only the
// relevant coordinates, i.e. from the top-leftmost live cell to
// bottom-rightmost live cell.
//
// You can represent a live cell with an asterisk (*) and a dead cell
// with a dot (.).

// I commented the solution with a finite board (using vector) and printing it whole.
// I did that first and struggled to get the infinite version
class Solution {
public:
    void gameOfLife(set<pair<int, int>>& live, int steps) {
        vector<pair<int, int>> directions = {
            {-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
            {0, 1}, {1, -1}, {1, 0}, {1, 1}
        };
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         int live = 0;
        //         for (pair<int, int> p : directions) {
        //             int x = i + p.first;
        //             int y = j + p.second;

        //             if (x >= 0 && x < n && y >= 0 && y < m) {
        //                 if (board[x][y] == '*' || board[x][y] == '/') {
        //                     live++;
        //                 }
        //             }
        //         }

        //         if (board[i][j] == '*' && (live < 2 || live > 3)) {
        //             board[i][j] = '/';
        //         } else if (board[i][j] == '.' && live == 3) {
        //             board[i][j] = '_';
        //         }
        //     }
        // }

        for (int step = 0; step < steps; ++step) {
            set<pair<int, int>> next_live;
            set<pair<int, int>> candidates;

            // All live cells and their neighbors are candidates for change
            for (auto cell : live) {
                candidates.insert(cell);
                for (auto d : directions) {
                    candidates.insert({cell.first + d.first, cell.second + d.second});
                }
            }

            // For each candidate, count live neighbors and apply rules
            for (auto cell : candidates) {
                int cnt = 0;
                for (auto d : directions) {
                    if (live.count({cell.first + d.first, cell.second + d.second})) {
                        cnt++;
                    }
                }
                if (live.count(cell)) {
                    if (cnt == 2 || cnt == 3) next_live.insert(cell);
                } else {
                    if (cnt == 3) next_live.insert(cell);
                }
            }

            live = next_live;
            printBoard(live);
            cout << endl;
        }
    }

    void printBoard(set<pair<int, int>>& live) {
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         if (board[i][j] == '_') {
        //             board[i][j] = '*';
        //         } else if (board[i][j] == '/') {
        //             board[i][j] = '.';
        //         }

        //         cout << board[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        //

        if (live.empty()) {
            cout << "(empty)" << endl;
            return;
        }
        int min_row = live.begin()->first, max_row = live.begin()->first;
        int min_col = live.begin()->second, max_col = live.begin()->second;
        for (auto cell : live) {
            min_row = min(min_row, cell.first);
            max_row = max(max_row, cell.first);
            min_col = min(min_col, cell.second);
            max_col = max(max_col, cell.second);
        }
        for (int i = min_row; i <= max_row; ++i) {
            for (int j = min_col; j <= max_col; ++j) {
                cout << (live.count({i, j}) ? '*' : '.');
            }
            cout << endl;
        }
    }
};

int main() {
    // Daily Coding Problem: Problem #39 [Medium] - 04/11/25
    Solution s;
    set<pair<int, int>> live = {
        {2, 1}, {2, 2}, {2, 3}
    };
    s.gameOfLife(live, 5);

    return 0;
}
