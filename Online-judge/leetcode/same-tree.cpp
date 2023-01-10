# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/same-tree/
 */

/*
Time complexity : O(N)
Space complexity : O(N)
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
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p || !q ) return p == q;
        if (p->val != q->val) return false;

        queue<TreeNode*>que;
        que.push(p);
        que.push(q);
        
        while(!que.empty()) {
            TreeNode* pp = que.front();
            que.pop();
            TreeNode* qq = que.front();
            que.pop();
            
            if ((pp->val != qq->val) || (pp->left && !qq->left) || (!pp->left && qq->left) || (pp->right && !qq->right) || (!pp->right && qq->right)) return false;

            if (pp->left && qq->left) {
                que.push(pp->left);
                que.push(qq->left);
            }
            if (pp->right && qq->right) {
                que.push(pp->right);
                que.push(qq->right);
            }
        }
        return true;
    }
};