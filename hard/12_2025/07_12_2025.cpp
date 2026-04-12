#include <iostream>
#include <unordered_map>
using namespace std;

// Daily Coding Problem: Problem #72 [Hard] - 07/12/25
//
// This problem was asked by Google.
// In a directed graph, each node is assigned an uppercase letter.
// We define a path's value as the number of most frequently-occurring letter along that path.
//
// For example, if a path in the graph goes through "ABACA", the value of the path is 3,
// since there are 3 occurrences of 'A' on the path.
//
// Given a graph with n nodes and m directed edges, return the largest value path of the graph.
// If the largest value is infinite, then return null.
//
// The graph is represented with a string and an edge list. The i-th character
// represents the uppercase letter of the i-th node. Each tuple in the edge list (i, j)
// means there is a directed edge from the i-th node to the j-th node.
// Self-edges are possible, as well as multi-edges.
//
// For example, the following input graph:
//
// ABACA
// [(0, 1),
//  (0, 2),
//  (2, 3),
//  (3, 4)]
//
// Would have maximum value 3 using the path of vertices [0, 2, 3, 4], (A, A, C, A).
// The following input graph:
//
// A
// [(0, 0)]
//
// Should return null, since we have an infinite loop.

struct Node {
    int key, val, freq;
    Node* prev;
    Node* next;

    Node(int k, int v) : key(k), val(v), freq(1), prev(nullptr), next(nullptr) {}
};

struct DLList {
    Node* head;
    Node* tail;
    int size;

    DLList() : size(0) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    void addToHead(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
        size++;
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        size--;
    }

    Node* removeTail() {
        if (size == 0) return nullptr;
        Node* node = tail->prev;
        removeNode(node);
        return node;
    }
};

class LFUCache {
    int capacity;
    int minFreq;
    unordered_map<int, Node*> keyMap;
    unordered_map<int, DLList*> freqMap;

public:
    LFUCache(int n) : capacity(n), minFreq(0) {}

    int get(int key) {
        if (keyMap.find(key) == keyMap.end()) {
            return -1;
        }

        Node* node = keyMap[key];
        int freq = node->freq;

        freqMap[freq]->removeNode(node);

        if (freq == minFreq && freqMap[freq]->size == 0) {
            minFreq++;
        }

        node->freq++;
        if (!freqMap.count(node->freq)) {
            freqMap[node->freq] = new DLList();
        }
        freqMap[node->freq]->addToHead(node);

        return node->val;
    }

    void set(int key, int value) {
        if (capacity == 0) return;

        if (keyMap.find(key) != keyMap.end()) {
            Node* node = keyMap[key];
            node->val = value;
            get(key);
            return;
        }

        if (keyMap.size() >= capacity) {
            DLList* list = freqMap[minFreq];
            Node* victim = list->removeTail();
            keyMap.erase(victim->key);
            delete victim;
        }

        Node* node = new Node(key, value);
        keyMap[key] = node;

        if (!freqMap.count(1)) {
            freqMap[1] = new DLList();
        }
        freqMap[1]->addToHead(node);
        minFreq = 1;
    }
};

int main() {
    // Daily Coding Problem: Problem #72 [Hard] - 07/12/25

    LFUCache cache(2);

    cache.set(1, 1);
    cache.set(2, 2);
    cout << cache.get(1) << endl; // 1
    cache.set(3, 3);              // evicts key 2
    cout << cache.get(2) << endl; // -1
    cout << cache.get(3) << endl; // 3
    cache.set(4, 4);              // evicts key 1
    cout << cache.get(1) << endl; // -1
    cout << cache.get(3) << endl; // 3
    cout << cache.get(4) << endl; // 4

    return 0;
}
