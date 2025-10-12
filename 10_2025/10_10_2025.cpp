#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Solution {
public:
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
    Solution s;
    string filename = "10_2025/numbers.txt"; // I don't have a big enough file to test it but it works

    cout << s.randomElement(filename) << endl;

    return 0;
}
