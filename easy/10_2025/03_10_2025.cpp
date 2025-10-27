#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

class Solution {
public:
    // Daily Coding Problem: Problem #8 [Easy] - 3/10/25

    // This problem was asked by Google.
    // A unival tree (which stands for "universal value") is a
    // tree where all nodes under it have the same value.
    // Given the root to a binary tree, count the number of unival subtrees.
    // For example, the following tree has 5 unival subtrees:
    //    0
    //   / \
    //  1   0
    //     / \
    //    1   0
    //   / \
    //  1   1

    int univalTreeNumber(TreeNode* root) {
        int count = 0;
        isUnival(root, count);
        return count;
    }

    bool isUnival(TreeNode* root, int& count) {
        // Leaf nodes are unival
        if (!root) return true;

        bool left = isUnival(root->left, count);
        bool right = isUnival(root->right, count);

        if (!left || !right) return false;
        if (root->left && root->left->val != root->val) return false;
        if (root->right && root->right->val != root->val) return false;

        count++;
        return true;
    }
};


int main() {
    Solution s;

    // Daily Coding Problem: Problem #8 [Easy] - 3/10/25
    TreeNode* root = new TreeNode(0, new TreeNode(1), new TreeNode(0, new TreeNode(1, new TreeNode(1), new TreeNode(1)), new TreeNode(0)));
    TreeNode* root2 = new TreeNode(5, new TreeNode(5, new TreeNode(5), new TreeNode(5)), new TreeNode(5));
    TreeNode* root3 = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3));
    TreeNode* root4 = new TreeNode(1);
    TreeNode* root5 = new TreeNode(1, new TreeNode(1, new TreeNode(1), new TreeNode(1)), new TreeNode(1, nullptr, new TreeNode(1)));

    cout << s.univalTreeNumber(root5) << endl;

    return 0;
}
