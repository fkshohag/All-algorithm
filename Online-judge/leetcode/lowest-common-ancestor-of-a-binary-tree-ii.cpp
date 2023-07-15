#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-ii/description/
 */

/**
 * @brief 
 * Time complexity : O((n))
 * Space complexity: O(n)
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
private:
    int count = 0;
    TreeNode* findAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return root;

        TreeNode* left = findAncestor(root->left, p, q);
        TreeNode* right = findAncestor(root->right, p, q);
        if (p == root || q == root) {
            count++;
            return root;
        }
        
        return left == NULL ? right : right == NULL ? left : root;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* lca = findAncestor(root, p, q);
        return count == 2 ? lca : NULL;
    }
};