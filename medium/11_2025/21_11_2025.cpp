#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

// Daily Coding Problem: Problem #56 [Medium] - 21/11/25
//
// This problem was asked by Google.
//
// Given an undirected graph represented as an adjacency matrix
// and an integer k, write a function to determine whether each
// vertex in the graph can be colored such that no two adjacent
// vertices share the same color using at most k colors.

class Solution {
public:
    bool canColor(vector<vector<bool>>& graph, vector<int>& colors, int c, int v) {
        for (int i = 0; i < graph.size(); i++) {
            if (graph[v][i] && colors[i] == c) {
                return false;
            }
        }

        return true;
    }

    bool color(vector<vector<bool>>& graph, vector<int>& colors, int k, int v, int n) {
        if (v == n) {
            return true;
        }

        for (int c = 0; c < k; c++) {
            if (canColor(graph, colors, c, v)) {
                colors[v] = c;

                if (color(graph, colors, k, v + 1, n)) {
                    return true;
                }
                colors[v] = -1;
            }
        }

        return false;
    }

    bool canBeColored(vector<vector<bool>>& graph, int k) {
        int n = graph.size();
        vector<int> colors(n, -1);

        return color(graph, colors, k, 0, n);
    }
};

int main() {
    Solution s;

    // Test cases generated with Claude

    cout << "=== Graph Coloring Test Cases ===" << endl;

    // Test Case 1: Triangle graph with k=2 (should be FALSE - impossible)
    cout << "Test 1 - Triangle with k=2: ";
    vector<vector<bool>> triangle = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}
    };
    cout << s.canBeColored(triangle, 2) << " (expected: 0)" << endl;

    // Test Case 2: Triangle graph with k=3 (should be TRUE)
    cout << "Test 2 - Triangle with k=3: ";
    cout << s.canBeColored(triangle, 3) << " (expected: 1)" << endl;

    // Test Case 3: Complete graph K4 with k=3 (should be FALSE)
    cout << "Test 3 - Complete K4 with k=3: ";
    vector<vector<bool>> complete4 = {
        {0, 1, 1, 1},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 0}
    };
    cout << s.canBeColored(complete4, 3) << " (expected: 0)" << endl;

    // Test Case 4: Complete graph K4 with k=4 (should be TRUE)
    cout << "Test 4 - Complete K4 with k=4: ";
    cout << s.canBeColored(complete4, 4) << " (expected: 1)" << endl;

    // Test Case 5: Path graph (linear) with k=2 (should be TRUE)
    cout << "Test 5 - Path graph with k=2: ";
    vector<vector<bool>> path = {
        {0, 1, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {0, 0, 1, 0}
    };
    cout << s.canBeColored(path, 2) << " (expected: 1)" << endl;

    // Test Case 6: Single vertex with k=1 (should be TRUE)
    cout << "Test 6 - Single vertex with k=1: ";
    vector<vector<bool>> single = {{0}};
    cout << s.canBeColored(single, 1) << " (expected: 1)" << endl;

    // Test Case 7: No edges (independent set) with k=1 (should be TRUE)
    cout << "Test 7 - No edges with k=1: ";
    vector<vector<bool>> noEdges = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    cout << s.canBeColored(noEdges, 1) << " (expected: 1)" << endl;

    // Test Case 8: Star graph with k=2 (should be TRUE)
    cout << "Test 8 - Star graph with k=2: ";
    vector<vector<bool>> star = {
        {0, 1, 1, 1},
        {1, 0, 0, 0},
        {1, 0, 0, 0},
        {1, 0, 0, 0}
    };
    cout << s.canBeColored(star, 2) << " (expected: 1)" << endl;

    // Test Case 9: Cycle of 4 vertices with k=2 (should be TRUE)
    cout << "Test 9 - 4-cycle with k=2: ";
    vector<vector<bool>> cycle4 = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };
    cout << s.canBeColored(cycle4, 2) << " (expected: 1)" << endl;

    // Test Case 10: Cycle of 3 vertices (triangle) with k=2 (should be FALSE)
    cout << "Test 10 - 3-cycle with k=2: ";
    cout << s.canBeColored(triangle, 2) << " (expected: 0)" << endl;

    return 0;
}
