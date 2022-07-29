# include <iostream>
# include <cstdio>
# include <vector>

using namespace std;


/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/binary-tree-preorder-traversal/
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
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) return ans;
        stack<TreeNode*> s;
        s.push(root);
        
        while (!s.empty()) {
            TreeNode* temp = s.top();
            s.pop();
            ans.push_back(temp->val);
            if(temp->right) {
                s.push(temp->right);
            }
            if(temp->left) {
                s.push(temp->left);
            }
        }
        return ans;
    }
};