#include <iostream>
#include <vector>
using namespace std;

// Daily Coding Problem: Problem #44 [Medium] - 09/11/25
//
// This problem was asked by Google.
// We can determine how "out of order" an array A is by counting
// the number of inversions it has. Two elements A[i] and A[j] form an
// inversion if A[i] > A[j] but i < j.
// That is, a smaller element appears after a larger element.
//
// Given an array, count the number of inversions it has.
// Do this faster than O(N^2) time.
// You may assume each element in the array is distinct.
//
// For example, a sorted list has zero inversions.
// The array [2, 4, 1, 3, 5] has three inversions: (2, 1), (4, 1), and (4, 3).
// The array [5, 4, 3, 2, 1] has ten inversions: every distinct pair forms an inversion.

class Solution {
public:
    int countInversions(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        return mergeSortAndCount(nums, 0, nums.size() - 1);
    }

    int mergeSortAndCount(vector<int>& nums, int left, int right) {
        int count = 0;
        if (left < right) {
            int mid = left + (right - left) / 2;
            count += mergeSortAndCount(nums, left, mid);
            count += mergeSortAndCount(nums, mid + 1, right);
            count += mergeAndCount(nums, left, mid, right);
        }

        return count;
    }

    int mergeAndCount(vector<int>& nums, int left, int mid, int right) {
        vector<int> leftNums(nums.begin() + left, nums.begin() + mid + 1);
        vector<int> rightNums(nums.begin() + mid + 1, nums.begin() + right + 1);

        int i = 0, j = 0, k = left;
        int count = 0;
        while (i < leftNums.size() && j < rightNums.size()) {
            if (leftNums[i] <= rightNums[j]) {
                nums[k++] = leftNums[i++];
            } else {
                nums[k++] = rightNums[j++];
                count += (leftNums.size() - i);
            }
        }

        while (i < leftNums.size()) {
            nums[k++] = leftNums[i++];
        }

        while (j < rightNums.size()) {
            nums[k++] = rightNums[j++];
        }

        return count;
    }
};

int main() {
    // Daily Coding Problem: Problem #44 [Medium] - 09/11/25
    Solution s;
    vector<int> test1 = {2, 4, 1, 3, 5};
    vector<int> test2 = {5, 4, 3, 2, 1};
    vector<int> test3 = {1, 2, 3, 4, 5};

    cout << "Array: [2, 4, 1, 3, 5]\n";
    cout << "Inversions: " << s.countInversions(test1) << "\n\n";

    cout << "Array: [5, 4, 3, 2, 1]\n";
    cout << "Inversions: " << s.countInversions(test2) << "\n\n";

    cout << "Array: [1, 2, 3, 4, 5]\n";
    cout << "Inversions: " << s.countInversions(test3) << "\n";

    return 0;
}
