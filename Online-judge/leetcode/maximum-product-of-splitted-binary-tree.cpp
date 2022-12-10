# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description/
 * Time complexity O(n)  
 * There are two places that extra space is used.
 * Firstly, the recursion is putting frames on the stack. 
 * The maximum number of frames at any one time is the maximum depth of the tree. For a balanced tree, 
 * this is around O(log⁡ n), and in the worst case (a long skinny tree) it is O(n).
 * Secondly, the list takes up space. It contains n−1 numbers at the end, so it too is O(n).
 * In both the average case and worst case, we have a total of O(n) space used by this approach.
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
public:
    typedef long long ll;
private:
    vector<ll> subTreeSum;
    ll solve(TreeNode* root) {
        if (!root) return 0;
        ll left = solve(root->left);
        ll right = solve(root->right);
        ll sum = root->val + left + right;
        subTreeSum.push_back(sum);
        return sum;
    }
    
public:
    int maxProduct(TreeNode* root) {
        ll best = 0;
        ll total = solve(root);
        for (int i = 0; i < subTreeSum.size(); i++) {
            ll subTree2 = total - subTreeSum[i]; 
            ll product = subTree2 * subTreeSum[i];
            best = max(best, product);
        }
        return int(best % 1000000007);
    }
};