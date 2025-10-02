#include <iostream>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    // Daily Coding Problem: Problem #3 [Medium] - 28/9/25 - Leetcode 297

    // This problem was asked by Google.
    // Given the root to a binary tree, implement:
    //   - serialize(root): Serializes the tree into a string.
    //   - deserialize(s): Deserializes the string back into the tree.
    //
    // For example, given the following Node class:
    //
    // class Node:
    //     def __init__(self, val, left=None, right=None):
    //         self.val = val
    //         self.left = left
    //         self.right = right
    //
    // The following test should pass:
    //
    // node = Node('root', Node('left', Node('left.left')), Node('right'))
    // assert deserialize(serialize(node)).left.left.val == 'left.left'
    string serialize(TreeNode* root) {
        // the idea is to start by the root value, then go by levels! BFS
        if (!root) return "nullptr";
        string str = "";

        queue<TreeNode*> bfs;
        bfs.push(root);
        while (!bfs.empty()) {
            int n = bfs.size();
            for (int i = 0; i < n; i++) {
                TreeNode* node = bfs.front();
                bfs.pop();

                if (node) {
                    bfs.push(node->left);
                    bfs.push(node->right);
                    str += to_string(node->val);
                    str += ',';
                } else {
                    str += "nullptr";
                    str += ',';
                }
            }
        }

        return str;
    }

    TreeNode* deserialize(string data) {
        if (data == "nullptr") return nullptr;
        stringstream ss(data);
        string token;
        getline(ss, token, ',');

        TreeNode* root = new TreeNode(stoi(token));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (!getline(ss, token, ',')) break;
            if (token != "nullptr") {
                node->left = new TreeNode(stoi(token));
                q.push(node->left);
            }

            if (!getline(ss, token, ',')) break;
            if (token != "nullptr") {
                node->right = new TreeNode(stoi(token));
                q.push(node->right);
            }
        }

        return root;
    }
};

int main() {
    Solution s;

    // Try it in Leetcode 297!
    // https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

    return 0;
}
