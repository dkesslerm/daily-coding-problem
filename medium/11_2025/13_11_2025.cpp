#include <compare>
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

// Daily Coding Problem: Problem #48 [Medium] - 13/11/25
//
// This problem was asked by Google.
// Given pre-order and in-order traversals of a binary tree,
// write a function to reconstruct the tree.
//
// For example, given the following preorder traversal:
// [a, b, d, e, c, f, g]
// And the following inorder traversal:
// [d, b, e, a, f, c, g]
// You should return the following tree:
//     a
//    / \
//   b   c
//  / \ / \
// d  e f  g

struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(' '), left(nullptr), right(nullptr) {}
    TreeNode(char val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(char val, TreeNode* left, TreeNode* right) :
        val(val), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* getTree(vector<char>& preorder, vector<char>& inorder) {
        deque<int> preorderDeque(preorder.begin(), preorder.end());
        return build(preorderDeque, inorder);
    }

    TreeNode* build(deque<int>& preorder, vector<char>& inorder) {
        if (!inorder.empty()) {
            char c = preorder.front();
            preorder.pop_front();
            auto it = find(inorder.begin(), inorder.end(), c);
            int idx = it - inorder.begin();

            TreeNode* root = new TreeNode(c);
            vector<char> leftInorder(inorder.begin(), inorder.begin() + idx);
            vector<char> rightInorder(inorder.begin() + idx + 1, inorder.end());

            root->left = build(preorder, leftInorder);
            root->right = build(preorder, rightInorder);

            return root;
        }

        return nullptr;
    }

    // claude created this
    void printTreeVisualHelper(TreeNode* root, string indent, bool isRight) {
            if (!root) return;

            cout << indent;
            if (isRight) {
                cout << "└── ";
                indent += "    ";
            } else {
                cout << "├── ";
                indent += "│   ";
            }
            cout << root->val << endl;

            if (root->left || root->right) {
                if (root->right) {
                    printTreeVisualHelper(root->right, indent, true);
                }
                if (root->left) {
                    printTreeVisualHelper(root->left, indent, false);
                }
            }
        }
};

int main() {
    // Daily Coding Problem: Problem #48 [Medium] - 13/11/25
    Solution s;
    vector<char> preorder = {'a', 'b', 'd', 'e', 'c', 'f', 'g'};
    vector<char> inorder = {'d', 'b', 'e', 'a', 'f', 'c', 'g'};

    TreeNode* tree = s.getTree(preorder, inorder);
    s.printTreeVisualHelper(tree, "", false);

    return 0;
}
