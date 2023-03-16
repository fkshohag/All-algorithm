#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 */

/**
 * @brief 
 * Time complexity : O(n)
 * Space complexity: O(1)
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
    TreeNode* dfs(int leftIndex, int rightIndex, vector<int>& inorder, vector<int>& postorder, map<int, int>& valVsIndex) {
        if (leftIndex > rightIndex) return NULL;
        int rootNode = postorder.back(); postorder.pop_back();

        int currentIndex = valVsIndex[rootNode];
        TreeNode* root = new TreeNode(rootNode);

        root->right = dfs(currentIndex + 1, rightIndex, inorder, postorder, valVsIndex);
        root->left = dfs(leftIndex, currentIndex - 1, inorder, postorder, valVsIndex);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> valVsIndex;
        for (int index = 0; index < inorder.size(); index++) {
            valVsIndex[inorder[index]] = index;
        }
        return dfs(0, inorder.size() - 1, inorder, postorder, valVsIndex);
    }
};