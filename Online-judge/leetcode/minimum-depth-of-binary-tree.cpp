# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/minimum-depth-of-binary-tree/
 * Running complexity O(n)
*/


 
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        if (root->left == nullptr && root->right == nullptr) return 1;
        
        int min_depth = INT_MAX;
        if (root->left) {
            min_depth = min(minDepth(root->left), min_depth);
        }
        if (root->right) {
            min_depth = min(minDepth(root->right), min_depth);
        }
        return min_depth+1;
    }
};