# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/same-tree/
 */

/*
Time complexity : O(N)O(N)
Space complexity : O(N)O(N)
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        if(p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};


class Solution {
public:
    bool isSameNode(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val != q->val) return false;
        return true;
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!isSameNode(p, q)) return false;
        queue<TreeNode*>que;
        que.push(p);
        que.push(q);
        
        while(!que.empty()) {
            TreeNode* pp = que.front();
            que.pop();
            TreeNode* qq = que.front();
            que.pop();
            
            if (!isSameNode(pp->left, qq->left)) return false;
            if (!pp->left) {
                que.push(pp->left);
                que.push(qq->right);
            }
            
            if (!isSameNode(pp->right, qq->right)) return false;
            if (!pp->right) {
                que.push(pp->right);
                que.push(qq->right);
            }
        }
        return true;
    }
};