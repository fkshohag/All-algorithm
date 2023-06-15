#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/
 * Time complexity: O(n).
 * Space complexity: O(n) stack for recursion call
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
    void solve(TreeNode* root, int level, vector<int>& res) {
        if (!root) return;
        if (res.size() == level) {
            res.push_back(root->val);
        } else {
            res[level] += root->val;
        }
        
        solve(root->left, level + 1, res);
        solve(root->right, level + 1, res);
    }

public:
    int maxLevelSum(TreeNode* root) {
        vector<int> res;
        this->solve(root, 0, res);
        int mx = INT_MIN;
        int index = 0;

        for (int i = 0; i < res.size(); i++) {
            if (res[i] > mx) {
                mx = res[i];
                index = i;
            }
        }
        return index + 1;
    }
};