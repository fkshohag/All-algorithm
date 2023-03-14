#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/sum-root-to-leaf-numbers/description/
 */

/**
 * @brief 
 * Time complexity : O(n)
 * Space complexity: O(1)
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    int sum;
    void solve(int number, TreeNode* root) {
        if (!root->left && !root->right) {
            sum += number * 10 + root->val;
        }
        int newNumber = number * 10 + root->val; 
        if (root->left) solve(newNumber, root->left);
        if (root->right) solve(newNumber, root->right);
    }

public:
    int sumNumbers(TreeNode* root) {
        sum = 0;
        solve(0, root);
        return sum;
    }
};