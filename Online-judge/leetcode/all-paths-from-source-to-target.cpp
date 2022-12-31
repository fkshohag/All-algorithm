# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/all-paths-from-source-to-target/description/
 * Time complexity O(V + E)
 * Space complexity O(V + E)
*/

class Solution {
private:
    void solve(vector<vector<int>>& graph, int source, int destination, vector<int> ans, vector<vector<int>>& res) {
        if (source == destination) {
            ans.push_back(source);
            res.push_back(ans);
        }
        ans.push_back(source);
        for (int vNode : graph[source]) {
            solve(graph, vNode, destination, ans, res);
        }
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> ans;
        vector<vector<int>> res;
        int n = int(graph.size() - 1);
        solve(graph, 0, n, ans, res);
        return res;
    }
};