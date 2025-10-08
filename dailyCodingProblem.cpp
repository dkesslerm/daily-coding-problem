#include <cctype>
#include <cstdint>
#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <chrono>
#include <thread>
#include <functional>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};


struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord = false;
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* current = root;
        for (char c : word) {
            if (!current->children[c]) {
                current->children[c] = new TrieNode();
            }
            current = current->children[c];
        }
        current->isEndOfWord = true;
    }

    bool search(string word) {
        TrieNode* current = root;
        for (char c : word) {
            if (!current->children[c]) {
                return false;
            }
            current = current->children[c];
        }

        return current->isEndOfWord;
    }

    bool startsWith(string prefix) {
        TrieNode* current = root;
        for (char c : prefix) {
            if (!current->children[c]) {
                return false;
            }
            current = current->children[c];
        }

        return true;
    }

    void collectWords(TrieNode* current, string prefix, vector<string>& result) {
        if (!current) return;

        if (current->isEndOfWord) {
            result.push_back(prefix);
        }

        for (auto it : current->children) {
            collectWords(it.second, prefix + it.first, result);
        }

    }

    vector<string> getWordsWithPrefix(string prefix) {
        vector<string> res;
        TrieNode* current = root;

        for (char c : prefix) {
            if (!current->children[c]) {
                return {};
            }
            current = current->children[c];
        }

        collectWords(current, prefix, res);

        return res;
    }
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

    // Daily Coding Problem: Problem #7 [Medium] - 2/10/25
    int numDecodings(string message) {
        int n = message.length();
        if (n == 0) return 0;
        int befprev = 1;
        int prev = (message[0] != '0');

        for (int i = 2; i <= n; i++) {
            int current = 0;

            if (message[i - 1] != '0') {
                current += prev;
            }
            int twoDigit = (message[i - 2] - '0') * 10 + (message[i - 1] - '0');
            if (twoDigit >= 10 && twoDigit <= 26) {
                current += befprev;
            }

            befprev = prev;
            prev = current;
        }

        return prev;
    }

    // Daily Coding Problem: Problem #8 [Easy] - 3/10/25
    int univalTreeNumber(TreeNode* root) {
        int count = 0;
        isUnival(root, count);
        return count;
    }

    bool isUnival(TreeNode* root, int& count) {
        if (!root) return true;

        bool left = isUnival(root->left, count);
        bool right = isUnival(root->right, count);

        if (!left || !right) return false;
        if (root->left && root->left->val != root->val) return false;
        if (root->right && root->right->val != root->val) return false;

        count++;
        return true;
    }

    // Daily Coding Problem: Problem #9 [Hard] - 4/10/25
    int largestSumOfNonAdjacentNumbers(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[n - 1];
    }

    // Daily Coding Problem: Problem #10 [Medium] - 5/10/25
    void jobScheduler(function<void()> f, int n) {
        this_thread::sleep_for(std::chrono::milliseconds(n));
        f();
    }

    // Daily Coding Problem: Problem #11 [Medium] - 6/10/25
    vector<string> autocomplete(vector<string> dictionary, string query) {
        Trie t;
        for (string s : dictionary) {
            t.insert(s);
        }
        return t.getWordsWithPrefix(query);
    }

    // Daily Coding Problem: Problem #12 [Hard] - 7/10/25
    int numberOfSteps(int n) {
        if (n == 1) return 1;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

// Daily Coding Problem: Problem #6 [Hard] - 1/10/25

struct Node {
    int data;
    Node* both; // XOR of prev and next nodes
};

class XORList {
private:
    Node* head = nullptr;
    Node* tail = nullptr;

    Node* XOR(Node* a, Node* b) {
        return (Node*)((uintptr_t)a ^ (uintptr_t)b);
    }
public:
    void add(int data) { // add at the end of the list
        Node* newNode = new Node();
        newNode->data = data;
        newNode->both = tail;

        if (tail) {
            tail->both = XOR(XOR(tail->both, nullptr), newNode);
        } else {
            head = newNode;
        }

        tail = newNode;
    }

    Node* get(int index) {
        Node* current = head;
        Node* prev = nullptr;
        int i = 0;
        while (current && i < index) {
            Node* next = XOR(prev, current->both);
            prev = current;
            current = next;
            i++;
        }
        return current;
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
        // auto pair = s.cons(1, "puerta");
        // cout << "First element: " << s.car(pair) << endl;
        // cout << "Second element: " << s.cdr(pair) << endl;

    // Daily Coding Problem: Problem #6 [Hard] - 1/10/25
        // XORList list;
        // list.add(3);
        // list.add(1);
        // list.add(8);

        // Node* node = new Node();
        // int index = 0;
        // node = list.get(index);
        // if (node) {
        //     cout << "The node at " << index << " has a value of " << node->data << endl;
        // } else {
        //     cout << "The node at " << index << " is null!" << endl;
        // }

    // Daily Coding Problem: Problem #7 [Medium] - 2/10/25
        // cout << s.numDecodings("101") << endl;
        // cout << s.numDecodings("110") << endl;
        // cout << s.numDecodings("2611055971756562") << endl;

    // Daily Coding Problem: Problem #8 [Easy] - 3/10/25
        // TreeNode* root = new TreeNode(0, new TreeNode(1), new TreeNode(0, new TreeNode(1, new TreeNode(1), new TreeNode(1)), new TreeNode(0)));
        // TreeNode* root2 = new TreeNode(5, new TreeNode(5, new TreeNode(5), new TreeNode(5)), new TreeNode(5));
        // TreeNode* root3 = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3));
        // TreeNode* root4 = new TreeNode(1);
        // TreeNode* root5 = new TreeNode(1, new TreeNode(1, new TreeNode(1), new TreeNode(1)), new TreeNode(1, nullptr, new TreeNode(1)));

        // cout << s.univalTreeNumber(root5) << endl;

    // Daily Coding Problem: Problem #9 [Hard] - 4/10/25
        // vector<int> nums = {5, 1, 1, 5}; // expected 10 = 5 + 5
        // vector<int> nums2 = {2, 4, 6, 2, 5}; // expected 13 = 2 + 6 + 5
        // cout << s.largestSumOfNonAdjacentNumbers(nums) << endl;

    // Daily Coding Problem: Problem #10 [Medium] - 5/10/25
        // function<void()> f = []() {
        //     cout << "Hello world!" << endl;
        // };

        // cout << "Waiting..." << endl;
        // s.jobScheduler(f, 2000);

    // Daily Coding Problem: Problem #11 [Medium] - 6/10/25
        vector<string> dict = {"dog", "deer", "deal"};
        string query = "d";
        vector<string> res = s.autocomplete(dict, query);
        cout << "[";
        for (string s : res) {
            for (char c : s) {
                cout << c;
            }
            cout << ", ";
        }
        cout << "\b\b]" << endl;

    // Daily Coding Problem: Problem #12 [Hard] - 7/10/25
    // cout << s.numberOfSteps(4);

    return 0;
}
