#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

// Daily Coding Problem: Problem #49 [Medium] - 14/11/25
//
// This problem was asked by Facebook.
//
// Given a function that generates perfectly random
// between 1 and k (inclusive), where k is an input, write
// a function that shuffles a deck of cards represented as
// an array using only swaps.
//
// It should run in O(N) time.
// Hint: Make sure each one of the 52! permutations of the deck is equally likely.

class Solution {
public:
    int randK(int k) {
        static random_device rd;
        static mt19937 gen(rd());
        uniform_int_distribution<> dis(1, k);
        return dis(gen);
    }

    void shuffleDeck(vector<int>& deck) {
        int n = deck.size();
        for (int i = n - 1; i > 0; i--) {
            swap(deck[i], deck[randK(i + 1) - 1]);
        }
    }

};

int main() {
    // Daily Coding Problem: Problem #49 [Medium] - 14/11/25
    Solution s;
    vector<int> deck;
    for (int i = 1; i <= 52; i++) {
        deck.push_back(i);
    }

    s.shuffleDeck(deck);

    for (int card : deck) {
        cout << card << " ";
    }

    return 0;
}
