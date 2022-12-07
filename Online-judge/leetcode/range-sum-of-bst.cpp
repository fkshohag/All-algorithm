#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/range-sum-of-bst/description/
 * Time complexity: O(n).
 * Space complexity: O(n)
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
    int ans;
    void rangeSum(TreeNode* root, int low, int high) {
        if (!root) return;
        if (root && root->val >= low && root->val <=high) {
            ans += root->val;
        }
        if (low < root->val) {
            rangeSum(root->left, low, high);
        } 
        if (root->val < high) {
            rangeSum(root->right, low, high);
        }
    }

public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        ans = 0;
        rangeSum(root, low, high);
        return ans;
    }
};

class Solution {
private:
    int ans;
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        ans = 0;
        stack<TreeNode*> s;
        s.push(root);

        while(!s.empty()) {
            TreeNode* node = s.top();
            s.pop();
            if (node) {
                if (node->val >= low && node->val <= high) {
                    ans += node->val;
                }
                if (low < node->val) {
                    s.push(node->left);
                }
                if (node->val < high) {
                    s.push(node->right);
                }
            }
        }
        return ans;
    }
};