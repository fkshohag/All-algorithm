# include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * @brief 
 * Time complexity: O(n)
 * Space complexity: O(n)
 * We don't use any auxiliary data structure, but the recursive call stack can go as deep as the tree's height. 
 * In the worst case, the tree is a linked list, so the height is nnn. Therefore, the space complexity is O(n).
 */
class Solution {
private:
    int maxSum;
    int sumPath(TreeNode* root) {
        if (!root) return 0;
        int left = max(sumPath(root->left), 0);
        int right = max(sumPath(root->right), 0);
        int sum =  root->val + left + right;
        maxSum = max(maxSum, sum);
        return max(left + root->val, right + root->val);
    }
public:
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        sumPath(root);
        return maxSum;
    }
};