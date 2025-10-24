#include <cinttypes>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

// Daily Coding Problem: Problem #26 [Medium] - 21/10/25
//
// This problem was asked by Google.
// Given a singly linked list and an integer k,
// remove the k-th last element from the list.
// k is guaranteed to be smaller than the length
// of the list.
//
// The list is very long, so making more than one
// pass is prohibitively expensive.
//
// Do this in constant space and in one pass.

struct Node {
    int val;
    Node* next;

    Node(int val, Node* next) : val(val), next(next) {}
    Node(int val) : val(val), next(nullptr) {}
};

class Solution {
public:
    Node* removeKthLastElement(Node* root, int k) {
        if (!root) return nullptr;

        Node* kthNext = root;
        Node* res = root;
        while (k > 0) {
            kthNext = kthNext->next;
            k--;
        }

        if (!kthNext) {
            cout << "k has to be smaller than the length of the list." << endl;
            return {};

            // If we wanted to allow removing the head, we would do this:
            // Node* toDelete = root;
            // root = root->next;
            // delete toDelete;
            // return root;
        }

        while (kthNext->next) {
            kthNext = kthNext->next;
            res = res->next;
        }

        Node* toDelete = res->next;
        if (toDelete) {
            res->next = toDelete->next;
            delete toDelete;
        }

        return root;
    }
};

void print(Node* root) {
    while (root) {
        cout << root->val;
        if (root->next) cout << " -> ";
        root = root->next;
    }
}

int main() {
    // Daily Coding Problem: Problem #26 [Medium] - 21/10/25
    Solution s;

    // 1 -> 2 -> 3 -> 4
    Node* root = new Node(1, new Node(2, new Node(3, new Node(4))));
    int k = 2; // remove 3

    root = s.removeKthLastElement(root, k);

    print(root);


    return 0;
}
