#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

class Solution {
public:
    // Daily Coding Problem: Problem #14 [Medium] - 9/10/25

    // This problem was asked by Google.
    // The area of a circle is defined as πr^2.
    // Estimate π to 3 decimal places using a Monte Carlo method.
    // Hint: The basic equation of a circle is x² + y² = r²
    //
    // I didn't know what a Monte Carlo algorithm was,
    // and the Wiki page explains it pretty well:
    // https://en.wikipedia.org/wiki/Monte_Carlo_algorithm
    // Basically, it's an algorithm where you are expected
    // to not have a correct output. You are certain to have
    // good efficiency, but probabilistic optimums.
    double monteCarloPi() {
        // The idea is to imagine a 2x2 square centered in (0,0) and
        // a circle of radius 1 also centered in (0,0). When you
        // generate a big amount of points (1e5, 1e9) inside of that
        // square, the probability that each point goes into the circle
        // is π / 4 (area of the circle / area of the square). Therefore,
        // in order to estimate π you have to calculate:
        // pi = 4 * points_inside / total_points.
        srand(std::time(0));
        int N = 1e5;
        int inside = 0;

        for (int i = 0; i < N; i++) {
            double x = (double)rand() / RAND_MAX * 2.0 - 1.0;
            double y = (double)rand() / RAND_MAX * 2.0 - 1.0;

            if (x*x + y*y <= 1.0) {
                inside++;
            }
        }

        double pi = 4.0 * inside / N;
        return pi;
    }
};

int main() {
    Solution s;

    // Daily Coding Problem: Problem #14 [Medium] - 9/10/25
    cout << "Estimated pi = " << fixed << setprecision(3) << s.monteCarloPi() << endl;

    return 0;
}
