# include <iostream>
# include <cstdio>
# include <cstring>
# include <cmath>
# include <utility>
# include <cstdlib>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/closest-binary-search-tree-value/
 * Running Complexity O(n), Space Complexity: O(1)
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
    int closestValue(TreeNode* root, double target) {
        int closest = root->val;
        while(root) {
            closest = abs(root->val - target) < abs(closest - target) ? root->val : closest;
            root = target < root->val ? root->left : root->right;
        }
        return closest;
    }
};