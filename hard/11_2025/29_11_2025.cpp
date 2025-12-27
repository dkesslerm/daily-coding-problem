#include <iostream>
#include <deque>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Daily Coding Problem: Problem #64 [Hard] - 29/11/25
//
// This problem was asked by Google.
// A knight's tour is a sequence of moves by a knight
// on a chessboard such that all squares are visited once.
//
// Given N, write a function to return the number of
// knight's tours on an N by N chessboard.

class Solution {
public:
    int numOfKnightTours(int n) {
        if (n == 1) return 1;
        if (n < 5) return 0;
        int num = 0;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                visited[i][j] = true;
                backtrack(visited, 1, i, j, n, num);
                visited[i][j] = false;
            }
        }

        return num;
    }

    bool isValid(int x, int y, int n, vector<vector<bool>>& visited) {
        return x >= 0 && x < n && y >= 0 && y < n && !visited[x][y];
    }

    void backtrack(vector<vector<bool>>& visited, int numVisited, int row, int col, int n, int& num) {
        if (numVisited == n * n) {
            num++;
            return;
        }

        int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
        int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

        for (int i = 0; i < 8; i++) {
            int nx = row + dx[i];
            int ny = col + dy[i];

            if (isValid(nx, ny, n, visited)) {
                visited[nx][ny] = true;
                backtrack(visited, numVisited + 1, nx, ny, n, num);
                visited[nx][ny] = false;
            }
        }
    }
};

int main() {
    // Daily Coding Problem: Problem #64 [Hard] - 29/11/25
    Solution s;

    cout << s.numOfKnightTours(6) << endl;
}
