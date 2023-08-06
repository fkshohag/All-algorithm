/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/unique-binary-search-trees-ii/description/
 * O(n)
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

    vector<TreeNode*> possibleTrees(int start, int end, map<pair<int, int>, vector<TreeNode*>>& memo) {
        vector<TreeNode*> ans;

        if (start > end) {
            ans.push_back(nullptr);
            return ans;
        }
        if (memo.find(make_pair(start, end)) != memo.end()) {
            return memo[make_pair(start, end)];
        }
        
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> leftNodes = possibleTrees(start, i - 1, memo);
            vector<TreeNode*> rightNodes = possibleTrees(i + 1, end, memo);

            for (auto left: leftNodes) {
                for (auto right: rightNodes) {
                    TreeNode* root = new TreeNode(i, left, right);
                    ans.push_back(root);
                }
            }
        }

        return memo[make_pair(start, end)] = ans;
    }

public:
    vector<TreeNode*> generateTrees(int n) {
        map<pair<int, int>, vector<TreeNode*>> memo;
        return possibleTrees(1, n, memo);
    }
};