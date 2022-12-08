#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
 * Time complexity: O(N).
 * Space complexity: O(N).
 */

class Solution {
private:
    void solve(TreeNode* root, int level, vector<vector<int>>& res) {
        if (!root) return;
        if (level == res.size()) {
            res.push_back({root->val});
        } else {
            res[level].push_back(root->val);
        }
        solve(root->left, level+1, res);
        solve(root->right, level+1, res);
     }
     
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        solve(root, 0, res);
        reverse(res.begin(), res.end());
        return res;
    }
};