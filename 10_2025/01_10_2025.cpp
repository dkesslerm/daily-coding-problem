#include <cstdint>
#include <iostream>
using namespace std;

// Daily Coding Problem: Problem #6 [Hard] - 1/10/25
// Took severe inspiration from:
// https://www.geeksforgeeks.org/dsa/xor-linked-list-a-memory-efficient-doubly-linked-list-set-1/

// This problem was asked by Google.
// An XOR linked list is a more memory efficient doubly linked list.
// Instead of each node holding next and prev fields, it holds a field
// named both, which is an XOR of the next node and the previous node.
//
// Implement an XOR linked list; it has an add(element) which adds the
// element to the end, and a get(index) which returns the node at index.

struct Node {
    int data;
    Node* both; // XOR of prev and next nodes
};

class XORList {
private:
    Node* head = nullptr;
    Node* tail = nullptr;

    Node* XOR(Node* a, Node* b) {
        return (Node*)((uintptr_t)a ^ (uintptr_t)b);
    }
public:
    void add(int data) { // add at the end of the list
        Node* newNode = new Node();
        newNode->data = data;
        newNode->both = tail;

        if (tail) {
            tail->both = XOR(tail->both, newNode);
        } else {
            head = newNode;
        }

        tail = newNode;
    }

    Node* get(int index) {
        Node* current = head;
        Node* prev = nullptr;
        int i = 0;
        while (current && i < index) {
            Node* next = XOR(prev, current->both);
            prev = current;
            current = next;
            i++;
        }
        return current;
    }
};

int main() {
    // Daily Coding Problem: Problem #6 [Hard] - 1/10/25
        XORList list;
        list.add(3);
        list.add(1);
        list.add(8);

        int index = 3;
        Node* node = list.get(index);

        if (node) {
            cout << "The node at index" << index << " has a value of " << node->data << endl;
        } else {
            cout << "The node at index" << index << " is null!" << endl;
        }

    return 0;
}
