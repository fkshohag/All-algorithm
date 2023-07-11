# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/editorial/
 * Running Complexity O(n), Space Complexity: O(n)
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
    unordered_map<int, vector<int>> graph;
    void buildGraph(TreeNode* curr, TreeNode* parent) {
        if (curr && parent) {
            if (this->graph.find(curr->val) == this->graph.end()) {
                this->graph[curr->val] = {};
            }
            if (this->graph.find(parent->val) == this->graph.end()) {
                this->graph[parent->val] = {};
            }
            this->graph[curr->val].push_back(parent->val);
            this->graph[parent->val].push_back(curr->val);
        }
        if (curr && curr->left) {
            buildGraph(curr->left, curr);
        }
        if (curr && curr->right) {
            buildGraph(curr->right, curr);
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        this->buildGraph(root, nullptr);

        unordered_map<int, bool> visited;
        visited[target->val] = true;
        queue<pair<int, int>> q;
        q.push({target->val, 0});
        vector<int> ans;

        while(!q.empty()) {
            auto node = q.front();
            q.pop();

            if (node.second == k) {
                ans.push_back(node.first);
            }
            
            for(int child : this->graph[node.first]) {
                if (visited.find(child) == visited.end()) {
                    visited[child] = true;
                    q.push({child, node.second + 1});
                }
            }
        }
        return ans;
    }
};