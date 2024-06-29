/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/boundary-of-binary-tree/
 * Time complexity: O(n)
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
    bool isLeaf(TreeNode* root) {
        if (!root->left && !root->right) {
            return true;
        }
        return false;
    }

    void addLeafNode(vector<int>& ans, TreeNode* node) {
        if (this->isLeaf(node)) {
            ans.push_back(node->val);
        }
        if (node->left) {
            this->addLeafNode(ans, node->left);
        }
        if (node->right) {
            this->addLeafNode(ans, node->right);
        }
    }

public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> ans;
        if (!root) {
            return ans;
        }
        if (!this->isLeaf(root)) {
            ans.push_back(root->val);
        }

        TreeNode* t = root->left;
        while (t) {
            if (!this->isLeaf(t)) {
                ans.push_back(t->val);
            }
            if (t->left) {
                t = t->left;
            } else {
                t = t->right;
            }
        }

        this->addLeafNode(ans, root);
        stack<int> rightNodes;
        t = root->right;
        
        while (t) {
            if (!this->isLeaf(t)) {
                rightNodes.push(t->val);
            }
            if (t->right) {
                t = t->right;
            } else {
                t = t->left;
            }
        }

        while(!rightNodes.empty()) {
            ans.push_back(rightNodes.top());
            rightNodes.pop();
        }
        return ans;
    }
};