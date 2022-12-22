#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/sum-of-distances-in-tree/description/
 * Time Complexity: O(N), where N is the number of nodes in the graph.
 * Space Complexity: O(N)
 */


class Solution {
private:
    vector<int> ans, count;
    vector<vector<int>> graph;
    int N;

    void dfs(int node, int parent) {
        for (auto& child : graph[node]) {
            if (child != parent) {
                dfs(child, node);
                count[node] += count[child];
                ans[node] += ans[child] + count[child];
            }
        }    
    }

    void dfs1(int node, int parent) {
        for (int child : graph[node]) {
            if (child != parent) {
                ans[child] = ans[node] - count[child] + N - count[child]; // parent - number of right node + number of left node
                dfs1(child, node);
            }
        }    
    }

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        graph = vector<vector<int>>(n, vector<int>());
        ans.resize(n, 0);
        count.resize(n, 1);
        N = n;

        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);          
        };

        dfs(0, -1);
        dfs1(0, -1);
        return ans;
    }
};