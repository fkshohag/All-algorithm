#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/description/
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
    int maxPath;
    int left, right;
    void dfs(TreeNode* root, int dir, int steps) {
        if (root) {
            this->maxPath = max(this->maxPath, steps);
            if (dir == this->left) {
                dfs(root->left, this->right, steps + 1);
                dfs(root->right, this->left, 1);
            } else {
                dfs(root->right, this->left, steps + 1);
                dfs(root->left, this->right, 1);
            }
        }
    }
public:
    int longestZigZag(TreeNode* root) {
        this->left = 1;
        this->right = 2;
        this->maxPath = 0;
        dfs(root, this->left, 0);
        dfs(root, this->right, 0);
        return this->maxPath;
    }
};