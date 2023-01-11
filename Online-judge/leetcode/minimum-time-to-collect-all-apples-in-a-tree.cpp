# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/description/
 * Time complexity O(N)
 * Space complexity O(N)
*/

class Solution {
private:
int dfs(int node, int parent, vector<vector<int>>& tree, vector<bool>& hasApple) {
    int totalTime = 0, childTime = 0;
    for (int child : tree[node]) {
        if (child == parent) continue;
        childTime = dfs(child, node, tree, hasApple);
        if (childTime || hasApple[child]) totalTime += childTime + 2;
    }
    return totalTime;
}

public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> tree(n);
        for (vector<int> edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        return dfs(0, -1, tree, hasApple);
    }
};