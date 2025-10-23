#include <cstdlib>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

// Daily Coding Problem: Problem #23 [Easy] - 18/10/25
//
// This problem was asked by Google.
// You are given an M by N matrix consisting of booleans that represents a board. Each True boolean represents a wall.
// Each False boolean represents a tile you can walk on.

// Given this matrix, a start coordinate, and an end coordinate, return the minimum number of steps required to reach
// the end coordinate from the start. If there is no possible path, then return null.
// You can move up, left, down, and right. You cannot move through walls. You cannot wrap around the edges of the board.

// For example, given the following board:

// [[f, f, f, f],
// [t, t, f, t],
// [f, f, f, f],
// [f, f, f, f]]

// and start = (3, 0) (bottom left) and end = (0, 0) (top left), the minimum number of steps required to reach the end is 7,
// since we would need to go through (1, 2) because there is a wall everywhere else on the second row.

struct Node {
    int x, y, dist;
};

class Solution {
public:
    bool isValid(int x, int y, vector<vector<bool>>& matrix, vector<vector<bool>>& visited) {
        return (x >= 0 && x < matrix.size() && y >= 0 && y < matrix[0].size() && !matrix[x][y] && !visited[x][y]);
    }

    int minNumberOfSteps(vector<vector<bool>>& matrix, pair<int, int> start, pair<int, int> end) {
        int m = matrix.size();
        int n = matrix[0].size();

        if (matrix[start.first][start.second] || matrix[end.first][end.second]) {
            return -1;
        }

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<Node> q;

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        q.push({start.first, start.second, 0});
        visited[start.first][start.second] = true;

        while (!q.empty()) {
            Node newNode = q.front();
            q.pop();

            if (newNode.x == end.first && newNode.y == end.second) {
                return newNode.dist;
            }

            for (pair<int, int> move : directions) {
                int nx = newNode.x + move.first;
                int ny = newNode.y + move.second;

                if (isValid(nx, ny, matrix, visited)) {
                    visited[nx][ny] = true;
                    q.push({nx, ny, newNode.dist + 1});
                }
            }
        }

        return -1;
     }
};

int main() {
    // Daily Coding Problem: Problem #23 [Easy] - 18/10/25
    Solution s;

    vector<vector<bool>> board = {
        {false, false, false, false},
        {true,  true,  false, true },
        {false, false, false, false},
        {false, false, false, false}
    };

    pair<int, int> start = {3, 0}; // bottom left
    pair<int, int> end   = {0, 0}; // top left

    int result = s.minNumberOfSteps(board, start, end);
    if (result == -1) {
        cout << "No path found" << endl;
    }
    else {
        cout << "Minimum steps: " << result << endl;
    }

    return 0;
}
