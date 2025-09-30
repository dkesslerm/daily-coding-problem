#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    // Daily Coding Problem: Problem #1 [Easy] - 26/9/25
    bool canAddUpToNumber(vector<int>& numbers, int k) {
        if (numbers.size() == 1) return false;
        unordered_map<int, int> remains;
        for (int n : numbers) {
            remains[n] = k - n;
        }

        for (int i = 0; i < numbers.size(); i++) {
            if (remains.find(k - numbers[i]) != remains.end()) {
                return true;
            }
        }

        return false;
    }

    // Daily Coding Problem: Problem #2 [Hard] - 27/9/25
    vector<int> multipliedArray(vector<int>& input) {
        // int multiplication = 1;
        // for (int i : input) {
        //     multiplication *= i;
        // }

        // vector<int> res(input.size(), multiplication);
        // for (int i = 0; i < input.size(); i++) {
        //     res[i] /= input[i];
        // }

        // return res;

        // Follow-up: what if you can't use division?

        int n = input.size();
        vector<int> res(n, 1);

        for (int i = 1; i < n; i++) {
            res[i] = res[i - 1] * input[i - 1];
        }

        int right = 1;
        for (int i = n - 1; i >= 0; i--) {
            res[i] *= right;
            right *= input[i];
        }

        return res;
    }

    // Daily Coding Problem: Problem #3 [Medium] - 28/9/25 - Leetcode 297
    // Serialize and deserialize a binary tree
    string serialize(TreeNode* root) {
        // the idea is to start by the root value, then go by levels! BFS
        if (!root) return "nullptr";
        string str = "";

        queue<TreeNode*> bfs;
        bfs.push(root);
        while (!bfs.empty()) {
            int n = bfs.size();
            for (int i = 0; i < n; i++) {
                TreeNode* node = bfs.front();
                bfs.pop();

                if (node) {
                    bfs.push(node->left);
                    bfs.push(node->right);
                    str += to_string(node->val);
                    str += ',';
                } else {
                    str += "nullptr";
                    str += ',';
                }
            }
        }

        return str;
    }

    TreeNode* deserialize(string data) {
        if (data == "nullptr") return nullptr;
        stringstream ss(data);
        string token;
        getline(ss, token, ',');

        TreeNode* root = new TreeNode(stoi(token));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (!getline(ss, token, ',')) break;
            if (token != "nullptr") {
                node->left = new TreeNode(stoi(token));
                q.push(node->left);
            }

            if (!getline(ss, token, ',')) break;
            if (token != "nullptr") {
                node->right = new TreeNode(stoi(token));
                q.push(node->right);
            }
        }

        return root;
    }

    // Daily Coding Problem: Problem #4 [Hard] - 29/9/25 - Leetcode 41
    int firstMissingPositive(vector<int> nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] < 1 || nums[i] > n) nums[i] = n + 1;
        }

        for (int i = 0; i < n; i++) {
            int num = abs(nums[i]);
            if (num > n) continue;

            num--;
            if (nums[num] > 0) {
                nums[num] *= -1;
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] >= 0) return i + 1;
        }

        return n + 1;
    }

    // Daily Coding Problem: Problem #5 [Medium] - 30/9/25
    // auto parameters in functions are a C++20 feature (compile with -std=c++20 if needed)
    auto cons(auto a, auto b) {
        return [a, b](auto f) {
            return f(a, b);
        };
    }

    auto car(auto pair) {
        return pair([](auto a, auto b) {
            return a;
        });
    }

    auto cdr(auto pair) {
        return pair([](auto a, auto b) {
            return b;
        });
    }



};

int main() {
    Solution s;

    // Daily Coding Problem: Problem #1 [Easy] - 26/9/25
        // vector<int> numbers = {3, 3, 3, 3};
        // int k = 6;
        // bool result = s.canAddUpToNumber(numbers, k);
        // cout << result << endl;

    // Daily Coding Problem: Problem #2 [Hard] - 27/9/25
        // vector<int> input = {1, 2, 3, 4, 5};
        // input = s.multipliedArray(input);

        // for (int i : input) {
        //     cout << i << ", ";
        // }

    // Daily Coding Problem: Problem #3 [Medium] - 28/9/25
        // Try it in Leetcode 297!

    // Daily Coding Problem: Problem #4 [Hard] - 29/9/25 - Leetcode 41
        // vector<int> nums = {-1, -1};
        // cout << s.firstMissingPositive(nums) << endl;

    // Daily Coding Problem: Problem #5 [Medium] - 30/9/25
        auto pair = s.cons(1, "puerta");
        cout << "First element: " << s.car(pair) << endl;
        cout << "Second element: " << s.cdr(pair) << endl;

    return 0;
}
