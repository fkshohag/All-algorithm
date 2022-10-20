# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/validate-binary-search-tree/submissions/
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */

 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    bool isValid(TreeNode* root, TreeNode* left, TreeNode* right) {
        if (root == nullptr) return true;
        if ((left && left->val >= root->val) || (right && right->val <= root->val)) return false;
        return isValid(root->left, left, root) && isValid(root->right, root, right);
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, nullptr, nullptr);
    }
};


class Solution {
private:
    int prev;
    bool first = true;
    bool isValid(int val) {
        if (first) {
            prev = val;
            first = false;
            return true;
        }
        if (prev >= val) return false;
        prev = val;
        return true;
    }
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        return (
            isValidBST(root->left)
            && isValid(root->val)
            && isValidBST(root->right)
        );
    }
};