#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/graph-valid-tree/
 */


class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int>representative (n, 0);
        
        for (int node = 0; node < n; node++) {
            representative[node] = node;
        }
        
        for (int index = 0; index < edges.size(); index++) {
            int u = edges[index][0];
            int v = edges[index][1];
            while (representative[u] != u) u = representative[u];
            while (representative[v] != v) v = representative[v];
            if (representative[u] == representative[v]) return false;
            representative[u] = v;
        }
        return edges.size() == n - 1;
    }
};

class Solution {
private: 
    vector<int> parent;
    
    int findParent(int x) {
        if (parent[x] == x) return parent[x];
        parent[x] = findParent(parent[x]);
        return parent[x];
    }
    bool make_union(int u, int v) {
        u = findParent(u);
        v = findParent(v);
        if (u == v) return false;
        parent[u] = v;
        return true;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        parent = vector<int>(n, 0);
        
        for (int node = 0; node < n; node++) {
            parent[node] = node;
        }
        
        for (int index = 0; index < edges.size(); index++) {
            int u = edges[index][0];
            int v = edges[index][1];
            if (!make_union(u, v)) return false;
        }
        return edges.size() == n - 1;
    }
};

class Solution {
private: 
    int nodeCount = 0;
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n, vector<int>());
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        bfs(graph, visited, 0);
        return n == nodeCount && edges.size() == n - 1;
    }
    
    void bfs(vector<vector<int>>& graph, vector<bool>visited, int node) {
        queue<int> q;
        q.push(node);
        visited[node] = true;
        nodeCount = 1;
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = 0; i < graph[u].size(); i++) {
                int v = graph[u][i];
                if (!visited[v]) {
                    q.push(v);
                    visited[v] = true;
                    nodeCount++;
                }
            }
        }
    }
};