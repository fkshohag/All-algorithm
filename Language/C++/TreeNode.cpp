# include <bits/stdc++.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(): val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

class Solution {
public:
	int closesVal(TreeNode* root, int target) {
		int closestValue = root->val;
		while(root) {
			closestValue = abs(target - root->val) < abs(target - closestValue) ? root->val : closestValue;
			root = target < root->val ? root->left : root->right;
		}
		return closestValue;
	}
};

int main() {
	int x = 34;
	TreeNode* root = new TreeNode(x);
	root->left = new TreeNode(2);
	Solution* s = new Solution();
	int k = s->closesVal(root, 1);
	printf("%d", k);
	return 0;
}