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

// Bfs solution

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        
        queue<TreeNode*> q;
        q.push(root);
        int ans = 1;
        
        while(!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                if (!node->left && !node->right) {
                    return ans;
                }
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            ans++;
        }
        return ans;
    }
};

// Recursion solution

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