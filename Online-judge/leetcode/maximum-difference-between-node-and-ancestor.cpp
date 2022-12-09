# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/
 * Time complexity O(n)  since we visit all nodes once.
 * space complexity O(n)  since we need stacks to do recursion, and the maximum depth of the recursion is the height of the tree, 
 * which is O(N) in the worst case and O(log⁡(N)) in the best case.
*/


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    int solve(TreeNode* root, int maxValue, int minValue) {
        if (!root) {
            return maxValue - minValue;
        }
        maxValue = max(maxValue, root->val);
        minValue = min(minValue, root->val);

        int left = solve(root->left, maxValue, minValue);
        int right = solve(root->right, maxValue, minValue);
        
        return max(left, right);
    }

public:
    int maxAncestorDiff(TreeNode* root) {
        return solve(root, root->val, root->val);
    }
};