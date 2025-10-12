#include <cstdlib>
#include <iostream>
#include <string>
#include <deque>
using namespace std;

// Daily Coding Problem: Problem #16 [Easy] - 11/10/25

// This problem was asked by Twitter.
// You run an e-commerce website and want to record the last N
// order ids in a log. Implement a data structure to accomplish
// this, with the following API:

//     record(order_id): adds the order_id to the log
//     get_last(i): gets the ith last element from the log.
//                  i is guaranteed to be smaller than or equal to N.

// You should be as efficient with time and space as possible.

class Log {
private:
    deque<string> logsData;
    int N;
public:
    Log(int n) {
        this->N = n;
    }

    void record(string order_id) {
        if (logsData.size() == N) {
            logsData.pop_front();
        }
        logsData.push_back(order_id);
    }

    string getLast(int i) {
        if (i <= 0 || i > logsData.size()) {
            return "Error! Index out of range";
        }
        return logsData[logsData.size() - i];
    }

    void printLog() {
        for (string s : logsData) {
            cout << s << endl;
        }
    }
};

int main() {
    // Daily Coding Problem: Problem #16 [Easy] - 11/10/25
    Log l(5);

    l.record("log1");
    l.record("log2");
    l.record("log3");
    l.record("log4");
    l.record("log5");

    l.printLog();
    cout << endl;

    l.record("log6");
    l.printLog();
    cout << endl;

    cout << l.getLast(2) << endl;

    return 0;
}
