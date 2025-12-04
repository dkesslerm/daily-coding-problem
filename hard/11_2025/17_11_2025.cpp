#include <iostream>
#include <deque>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Daily Coding Problem: Problem #52 [Hard] - 17/11/25
//
// This problem was asked by Google.
//
// Implement an LRU (Least Recently Used) cache.
// It should be able to be initialized with a cache size n,
// and contain the following methods:
//
// - set(key, value): sets key to value.
//   If there are already n items in the cache and we are adding a new item,
//   then it should also remove the least recently used item.
//
// - get(key): gets the value at key.
//   If no such key exists, return null.
//
// Each operation should run in O(1) time.

struct Node {
    int key, val;
    Node* prev;
    Node* next;
    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
    int size;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;

    void moveToHead(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;

        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    Node* popTail() {
        Node* lastNode = tail->prev;
        lastNode->prev->next = lastNode->next;
        lastNode->next->prev = lastNode->prev;
        return lastNode;
    }

public:
    LRUCache(int n) : size(n) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        Node* node = cache[key];
        moveToHead(node);
        return node->val;
    }

    void set(int key, int value) {
        if (cache.find(key) == cache.end()) {
            Node* newNode = new Node(key, value);

            if (cache.size() >= size) {
                Node* tail = popTail();
                cache.erase(tail->key);
                delete tail;
            }

            cache[key] = newNode;
            newNode->prev = head;
            newNode->next = head->next;
            head->next->prev = newNode;
            head->next = newNode;
        } else {
            Node* node = cache[key];
            node->val = value;
            moveToHead(node);
        }
    }
};

int main() {
    // Daily Coding Problem: Problem #52 [Hard] - 17/11/25
    LRUCache cache(2);

    cache.set(1, 1);
    cache.set(2, 2);
    cout << cache.get(1) << endl; // returns 1
    cache.set(3, 3);              // evicts key 2
    cout << cache.get(2) << endl; // returns -1 (not found)
    cache.set(4, 4);              // evicts key 1
    cout << cache.get(1) << endl; // returns -1 (not found)
    cout << cache.get(3) << endl; // returns 3
    cout << cache.get(4) << endl; // returns 4

    return 0;
}
