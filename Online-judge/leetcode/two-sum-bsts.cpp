# include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * @brief 
 * Problem: https://leetcode.com/problems/two-sum-bsts/description/
 * Time complexity: O(m * n)
 * Space complexity: O(n + n)
 */

class Solution {
private:
    void dfs1(TreeNode* node, vector<int>& list) {
        if (!node) return;
        list.push_back(node->val);
        dfs1(node->left, list);
        dfs1(node->right, list);
    }

    void dfs2(TreeNode* node, unordered_set<int>& list) {
        if (!node) return;
        list.insert(node->val);
        dfs2(node->left, list);
        dfs2(node->right, list);
    }
    
public:
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        vector<int> list1;
        unordered_set<int> list2;

        dfs1(root1, list1);
        dfs2(root2, list2);

        for (int val : list1) {
            if (list2.find(target - val) != list2.end()) return true;
        }
        return false;
    }
};