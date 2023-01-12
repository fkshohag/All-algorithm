# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/description/
 * Time complexity O(26*N) = O(N)
 * Space complexity O(26*N) = O(N)
*/

class Solution {
private:
    vector<int> dfs(int node, int parent, vector<vector<int>>& tree, vector<int>& ans, string& labels) {
        vector<int> nodeCount(26);
        nodeCount[labels[node] - 'a'] = 1;

        for (int child : tree[node]) {
            if (child == parent) continue;
            vector<int> childCount = dfs(child, node, tree, ans, labels);
            for (int i = 0; i < 26; i++) {
                nodeCount[i] += childCount[i]; 
            }
        }
        ans[node] = nodeCount[labels[node] - 'a'];
        return nodeCount;
    }
    
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> ans(n, 0);
        vector<vector<int>> tree(n);
        for (auto& edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        dfs(0, -1, tree, ans, labels);
        return ans;
    }
};