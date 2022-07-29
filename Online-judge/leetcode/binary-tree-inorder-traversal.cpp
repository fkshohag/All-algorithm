# include <iostream>
# include <cstdio>
# include <vector>

using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/binary-tree-inorder-traversal/
 */



 // Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
Recursion solution
Ordering
left->root->right
Complexity: 
Time Complexity: O(n) 2.T(n/2) + 1 
Space Complexity: O(n)
*/

class Solution {
public:
    void inorder(TreeNode *root, vector<int> &ans) {
        if (root == nullptr) return;
        if (root->left) inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
};




/*
Loop solution
Ordering
left->root->right
Complexity: 
Time Complexity: O(n)
Space Complexity: O(n)
*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ans;
        if (!root) return ans;
        bool isMoveToRight = false;
		stack <TreeNode*> s;
		s.push(root);

		while (!s.empty()) {
			TreeNode* temp = s.top();

			if (isMoveToRight) {
				ans.push_back(temp->val);
				s.pop();

				if (temp->right) {
					s.push(temp->right);
					isMoveToRight = false;
				}
			}
			else {
				if (temp->left) {
					s.push(temp->left);
				}
				else {
					isMoveToRight = true;
				}
			}
		}
        return ans;
    }
};