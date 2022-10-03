#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/
 * Time complexity: {O}(E + V)O(E+V).
 * Space complexity: {O}(E + V)O(E+V).
 */


class Solution {
private: 
    int number_of_component = 0;
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>graph(n, vector<int>());
        vector<bool>visited(n, false);
        
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                number_of_component++;
                dfs(graph, visited, i);
            }
        }
        return number_of_component;
    }

    void dfs(vector<vector<int>>& graph, vector<bool>& visited, int node) {
        visited[node] = true;
        for (int i = 0; i < graph[node].size(); i++) {
            int v = graph[node][i];
            if (!visited[v]) {
                dfs(graph, visited, v);
            }
        }
    }
};