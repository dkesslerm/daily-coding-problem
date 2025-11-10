#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Daily Coding Problem: Problem #41 [Medium] - 06/11/25
//
// This problem was asked by Facebook.
// Given an unordered list of flights taken by someone, each represented
// as (origin, destination) pairs, and a starting airport, compute the
// person's itinerary. If no such itinerary exists, return null. If there
// are multiple possible itineraries, return the lexicographically smallest
// one. All flights must be used in the itinerary.
//
// For example:
// - Given the list of flights
//   [('SFO', 'HKO'), ('YYZ', 'SFO'), ('YUL', 'YYZ'), ('HKO', 'ORD')]
//   and starting airport 'YUL', you should return the list
//   ['YUL', 'YYZ', 'SFO', 'HKO', 'ORD'].
//
// - Given the list of flights
//   [('SFO', 'COM'), ('COM', 'YYZ')]
//   and starting airport 'COM', you should return null.
//
// - Given the list of flights
//   [('A', 'B'), ('A', 'C'), ('B', 'C'), ('C', 'A')]
//   and starting airport 'A', you should return the list
//   ['A', 'B', 'C', 'A', 'C'] even though ['A', 'C', 'A', 'B', 'C']
//   is also a valid itinerary. However, the first one is lexicographically
//   smaller.

class Solution {
public:
    vector<string> getItinerary(vector<pair<string, string>>& flights, string startingAirport) {
        unordered_map<string, vector<string>> stops;
        for (pair<string, string> f : flights) {
            stops[f.first].push_back(f.second);
        }

        string curr = startingAirport;
        int flightsUsed = 0;
        vector<string> res;

        while (stops.find(curr) != stops.end() && flightsUsed < flights.size()) {
            vector<string>& currVector = stops[curr];
            flightsUsed++;
            res.push_back(curr);
            auto minIt = min_element(currVector.begin(), currVector.end());
            string next = *minIt;

            currVector.erase(minIt);
            if (currVector.empty()) {
                stops.erase(curr);
            }

            curr = next;
        }
        res.push_back(curr);

        if (flightsUsed < flights.size()) return {};
        return res;
    }
};

int main() {
    // Daily Coding Problem: Problem #41 [Medium] - 06/11/25
    Solution s;
    vector<pair<string, string>> flights1 = {
        {"SFO", "HKO"}, {"YYZ", "SFO"},
        {"YUL", "YYZ"}, {"HKO", "ORD"}
    };
    string startingAirport1 = "YUL";

    vector<pair<string, string>> flights2 = {
        {"SFO", "COM"}, {"COM", "YYZ"},
    };
    string startingAirport2 = "COM";

    vector<pair<string, string>> flights3 = {
        {"A", "B"}, {"A", "C"},
        {"B", "C"}, {"C", "A"}
    };
    string startingAirport3 = "A";

    cout << "Expected: [YUL, YYZ, SFO, HKO, ORD]" << endl;
    cout << "Got: [";
    for (string str : s.getItinerary(flights1, startingAirport1)) {
        cout << str << ", ";
    }
    cout << "\b\b]" << endl;

    cout << "Expected: []" << endl;
    cout << "Got: [";
    for (string str : s.getItinerary(flights2, startingAirport2)) {
        cout << str << ", ";
    }
    cout << "]" << endl;

    cout << "Expected: [A, B, C, A, C]" << endl;
    cout << "Got: [";
    for (string str : s.getItinerary(flights3, startingAirport3)) {
        cout << str << ", ";
    }
    cout << "\b\b]" << endl;


    return 0;
}
