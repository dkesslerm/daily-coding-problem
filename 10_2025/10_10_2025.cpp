#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Solution {
public:
    // Daily Coding Problem: Problem #15 [Medium] - 10/10/25
    //
    // This problem was asked by Facebook.
    // Given a stream of elements too large to store in memory,
    // pick a random element from the stream with uniform probability.
    int randomElement(string filename) {
        srand(time(0));
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "Error opening file!" << endl;
            return 1;
        }

        string line;
        long count = 0;
        int res;
        while (getline(file, line)) {
            count++;
            if (rand() % count == 0) {
                res = stoi(line);
            }
        }

        file.close();

        return res;
    }
};

int main() {
    // Daily Coding Problem: Problem #15 [Medium] - 10/10/25
    Solution s;
    string filename = "10_2025/numbers.txt"; // I don't have a big enough file to test it but it works

    cout << s.randomElement(filename) << endl;

    return 0;
}
