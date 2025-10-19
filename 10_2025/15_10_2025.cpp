#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

// Daily Coding Problem: Problem #20 [Easy] - 15/10/25
//
// This problem was asked by Google.
// Given two singly linked lists that intersect at some point, find the intersecting node.
// The lists are non-cyclical.

// Example:
// List A: 3 -> 7 -> 8 -> 10
// List B: 99 -> 1 -> 8 -> 10
// Output: Return the node with value 8.

// Note:
// - Assume nodes with the same value are the exact same node objects.
// - Solve this in O(M + N) time, where M and N are the lengths of the lists,
//   and use constant space.

class Node {
public:
    int val;
    Node* next;

    Node(int val, Node* next) {
        this->val = val;
        this->next = next;
    }
};


class Solution {
public:
    Node* findIntersection(Node* listA, Node* listB) {
        // if (!listA || !listB) return nullptr;
        // Node* n1 = listA;
        // Node* n2 = listB;
        // while (n1) {
        //     n2 = listB;
        //     while (n2) {
        //         if (n1->val == n2->val) {
        //             return n1;
        //         }
        //         n2 = n2->next;
        //     }
        //     n1 = n1->next;
        // }
        // return nullptr;

        if (!listA || !listB) return nullptr;

        Node* n1 = listA;
        Node* n2 = listB;

        while (n1 != n2) {
            n1 = n1 ? n1->next : listB;
            n2 = n2 ? n2->next : listA;
        }

        return n1;
    }
};

int main() {
    // Daily Coding Problem: Problem #20 [Easy] - 15/10/25
    Solution s;
    Node* intersection = new Node(8, new Node(10, nullptr));
    Node* listA = new Node(3, intersection);
    Node* listB = new Node(99, new Node(1, intersection));

    Node* res = s.findIntersection(listA, listB);
    if (res) {
        cout << res->val << endl;
    } else {
        cout << "No common nodes between both lists" << endl;
    }

    return 0;
}
