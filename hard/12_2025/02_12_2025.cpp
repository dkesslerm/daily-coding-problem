#include <iostream>
#include <unordered_map>
using namespace std;

// Daily Coding Problem: Problem #52 [Hard] - 17/11/25
//
// This problem was asked by Google.
// Implement an LFU (Least Frequently Used) cache.
// It should be able to be initialized with a cache size n, and contain the following methods:
//
// - set(key, value): sets key to value. If there are already n items in
// the cache and we are adding a new item, then it should also remove the least frequently used item.
// If there is a tie, then the least recently used key should be removed.
//
// - get(key): gets the value at key. If no such key exists, return null.
//
// Each operation should run in O(1) time.

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
