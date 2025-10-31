#include <iostream>
using namespace std;

// Daily Coding Problem: Problem #34 [Medium] - 29/10/25
//
// This problem was asked by Dropbox.
// Given the root to a binary search tree, find the second largest node in the tree.

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val, TreeNode* left, TreeNode* right) : val(val), left(left), right(right) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    TreeNode* root;
public:
    BinarySearchTree() : root(nullptr) {}
    BinarySearchTree(TreeNode* root) : root(root) {}

    void printTree(TreeNode* root) {
        if (!root) return;

        printTree(root->left);
        cout << root->val << " ";
        printTree(root->right);
    }

    void addVal(int val) {
        if (!root) {
            root = new TreeNode(val, nullptr, nullptr);
            return;
        }

        TreeNode* cur = root;
        while (true) {
            if (cur->val < val) {
                if (cur->right) {
                    cur = cur->right;
                } else {
                    cur->right = new TreeNode(val);
                    break;
                }
            } else {
                if (cur->left) {
                    cur = cur->left;
                } else {
                    cur->left = new TreeNode(val);
                    break;
                }
            }
        }
    }

    TreeNode* findSecondLargestNode() {
        if (!root) return nullptr;
        if (!root->left && !root->right) return nullptr;

        TreeNode* cur = root;
        TreeNode* parent = nullptr;
        while (cur->right) {
            parent = cur;
            cur = cur->right;
        }

        if (cur->left) {
            TreeNode* aux = cur->left;
            while (aux->right) {
                aux = aux->right;
            }
            return aux;
        }

        return parent;
    }
};

int main() {
    // Daily Coding Problem: Problem #34 [Medium] - 29/10/25

    BinarySearchTree t1;
    t1.addVal(1); t1.addVal(2); t1.addVal(-1); t1.addVal(5); t1.addVal(7);
    cout << "Test 1 (Expected 5): " << (t1.findSecondLargestNode() ? t1.findSecondLargestNode()->val : -1) << endl;

    BinarySearchTree t2;
    t2.addVal(10); t2.addVal(20);
    cout << "Test 2 (Expected 10): " << (t2.findSecondLargestNode() ? t2.findSecondLargestNode()->val : -1) << endl;

    BinarySearchTree t3;
    t3.addVal(50); t3.addVal(30); t3.addVal(20); t3.addVal(10);
    cout << "Test 3 (Expected 30): " << (t3.findSecondLargestNode() ? t3.findSecondLargestNode()->val : -1) << endl;

    BinarySearchTree t4;
    t4.addVal(100);
    cout << "Test 4 (Expected -1): "
        << (t4.findSecondLargestNode() ? t4.findSecondLargestNode()->val : -1) << endl;

    BinarySearchTree t5;
    t5.addVal(10); t5.addVal(5); t5.addVal(15); t5.addVal(12); t5.addVal(20);
    cout << "Test 5 (Expected 15): " << (t5.findSecondLargestNode() ? t5.findSecondLargestNode()->val : -1) << endl;

    BinarySearchTree t6;
    t6.addVal(8); t6.addVal(3); t6.addVal(10); t6.addVal(1); t6.addVal(6); t6.addVal(14); t6.addVal(13);
    cout << "Test 6 (Expected 13): " << (t6.findSecondLargestNode() ? t6.findSecondLargestNode()->val : -1) << endl;

    BinarySearchTree t7;
    t7.addVal(40); t7.addVal(20); t7.addVal(60); t7.addVal(50); t7.addVal(70); t7.addVal(65); t7.addVal(80);
    cout << "Test 7 (Expected 70): " << (t7.findSecondLargestNode() ? t7.findSecondLargestNode()->val : -1) << endl;

    BinarySearchTree t8;
    t8.addVal(5); t8.addVal(4); t8.addVal(3); t8.addVal(2); t8.addVal(1);
    cout << "Test 8 (Expected 4): " << (t8.findSecondLargestNode() ? t8.findSecondLargestNode()->val : -1) << endl;

    BinarySearchTree t9;
    t9.addVal(10); t9.addVal(8); t9.addVal(9); t9.addVal(15); t9.addVal(14);
    cout << "Test 9 (Expected 14): " << (t9.findSecondLargestNode() ? t9.findSecondLargestNode()->val : -1) << endl;

    BinarySearchTree t10;
    t10.addVal(100); t10.addVal(50); t10.addVal(150); t10.addVal(125); t10.addVal(175); t10.addVal(160); t10.addVal(180);
    cout << "Test 10 (Expected 175): " << (t10.findSecondLargestNode() ? t10.findSecondLargestNode()->val : -1) << endl;

    return 0;
}
