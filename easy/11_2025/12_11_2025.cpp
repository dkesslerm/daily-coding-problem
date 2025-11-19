#include <iostream>
#include <random>
#include <map>
using namespace std;

// Daily Coding Problem: Problem #47 [Easy] - 12/11/25
//
// This problem was asked by Facebook.
// Given a array of numbers representing the stock prices of a company
// in chronological order, write a function that calculates the maximum
// profit you could have made from buying and selling that stock once.
// You must buy before you can sell it.
//
// For example, given [9, 11, 8, 5, 7, 10], you should return 5,
// since you could buy the stock at 5 dollars and sell it at 10 dollars.

class Solution {
public:
    int maxProfitFromStocks(vector<int>& prices) {
        int maxProfit = 0;

        int n = prices.size();
        int left = 0;
        for (int i = 1; i < n; i++) {
            int currProfit = prices[i] - prices[left];
            if (currProfit < 0) {
                left = i;
            }
            currProfit = prices[i] - prices[left];
            maxProfit = max(maxProfit, currProfit);
        }

        return maxProfit;
    }
};

int main() {
    // Daily Coding Problem: Problem #47 [Easy] - 12/11/25
    Solution s;

    vector<int> stockPrices = {9, 11, 8, 5, 7, 10};
    cout << "Expected: 5, Got: " << s.maxProfitFromStocks(stockPrices) << endl;

    return 0;
}
