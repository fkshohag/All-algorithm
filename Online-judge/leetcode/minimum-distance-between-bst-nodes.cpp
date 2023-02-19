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
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
 * Running complexity O(n)
 * Memory complexity O(log(n))
*/


class Solution {
private:
    vector<int> nodes;

    void dfs(TreeNode* root) {
        if (!root) return;
        nodes.push_back(root->val);
        dfs(root->left); dfs(root->right);
    }
    
public:
    int minDiffInBST(TreeNode* root) {
        dfs(root);
        sort(nodes.begin(), nodes.end());
        int res = INT_MAX;
        
        for (int i = 1; i < nodes.size(); i++) {
            if (nodes[i] - nodes[i-1] < res) {
                res = nodes[i] - nodes[i-1];
            }
        }
        return res;
    }
};