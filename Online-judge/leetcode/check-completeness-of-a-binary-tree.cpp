#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/check-completeness-of-a-binary-tree/description/
 */

/**
 * @brief 
 * Time complexity : O(n)
 * Space complexity: O(n)
 */

class Solution {
private:
    int nodeCount(TreeNode* root) {
        if (!root) return 0;
        return 1 + nodeCount(root->left) + nodeCount(root->right);
    }
    bool isTree(TreeNode* root, int index, int n) {
        if (!root) return true;
        if (index >= n) return false;
        return isTree(root->left, index * 2 + 1, n) && isTree(root->right, index * 2 + 2, n);
    }
public:
    bool isCompleteTree(TreeNode* root) {
        return isTree(root, 0, nodeCount(root));
    }
};