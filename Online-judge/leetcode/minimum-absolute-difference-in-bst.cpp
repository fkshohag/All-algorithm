#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/
 * Time complexity: O(n).
 * Space complexity: O(n).
 * Solution -> second
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

 /**
 * time complexity: O(nlogn) -> sorting
 * space complexity: O(n)
 **/
class Solution {
private:
    vector<int> values;
    void dfs(TreeNode* root) {
        if (!root) return;
        values.push_back(root->val);

        dfs(root->left);
        dfs(root->right);
    }

public:
    int getMinimumDifference(TreeNode* root) {
        this->dfs(root);
        sort(this->values.begin(), this->values.end());

        int minDiff = INT_MAX;
        for (int i = 0; i < this->values.size() - 1; i++) {
            minDiff = min(minDiff, this->values[i + 1] - this->values[i]);
        }
        return minDiff;
    }
};

/**
* time complexity: O(N)
* space complexity: O(N)
**/
class Solution {
private:
    vector<int> inorderNodes;
    void dfs(TreeNode* node) {
        if (!node) return;

        this->dfs(node->left);
        this->inorderNodes.push_back(node->val);
        this->dfs(node->right);
    }

public:
    int getMinimumDifference(TreeNode* root) {
        this->dfs(root);

        int minDiff = INT_MAX;
        for (int i = 0; i < this->inorderNodes.size() - 1; i++) {
            minDiff = min(minDiff, this->inorderNodes[i + 1] - this->inorderNodes[i]);
        }
        return minDiff;
    }
};