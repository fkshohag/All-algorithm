#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/invert-binary-tree/description/
 * Complexity: running O(n) 
 * Space O(1)
 */

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        root->left = invertTree(right);
        root->right = invertTree(left);
        return root;
    }
};